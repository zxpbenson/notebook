package main

/*
* 设定场景
* 创建一个文件存放数据
* 每次写操作都想文件写入若干字节数据
* 这若干字节被称为一个独立的数据块
* 写操作之间不能互相干扰，也就是书库快之间不能出现穿插和混淆
* 读取操作也一样，能读到一个完整独立的数据块，且不能重复，还要顺序读
* 不要求是否可以并发，即使并发进行，程序也能改分辨出他们的先后顺序
* 此外设定每个数据块长度相同，该长度在读写写操作进行前给定
* 若实际写入长度超过该值，超长部分将会被截掉
 */

import (
	"errors"
	"fmt"
	"io"
	"os"
	"sync"
)

type Data []byte

type DataFile interface {
	Read() (rsn int64, d Data, err error) //读取一个数据块
	Write(d Data) (wsn int64, err error)  //写入一个数据块
	RSN() int64                           //获取最后读取数据块的序号
	WSN() int64                           //获取最后写入数据块的序号
	DataLen() uint32                      //获取数据块长度
	Close() error                         //关闭数据文件
}

type myDataFile struct {
	f       *os.File     //文件
	fMutex  sync.RWMutex //用于文件读写的锁
	wOffset int64        //写操作需要用到的偏移量
	rOffset int64        //读操作需要用到的偏移量
	wMutex  sync.Mutex   //写操作需要用到的互斥锁
	rMutex  sync.Mutex   //读操作需要用到的互斥锁
	dataLen uint32       //数据块长度
}

func NewDataFile(path string, dataLen uint32) (DataFile, error) {
	if dataLen == 0 {
		return nil, errors.New(fmt.Sprintf("Invalid data length : %v", dataLen))
	}

	f, err := os.Create(path)
	if err != nil {
		return nil, err
	}
	return &myDataFile{f: f, dataLen: dataLen}, nil
}

func (this *myDataFile) ReadV1() (rsn int64, d Data, err error) {

	//读取并更新偏移量
	var offset int64
	this.rMutex.Lock()
	offset = this.rOffset
	this.rOffset += int64(this.dataLen)
	this.rMutex.Unlock()

	//读取一个数据块
	rsn = offset
	this.fMutex.RLock()
	defer this.fMutex.RUnlock()
	bytes := make([]byte, this.dataLen)
	_, err = this.f.ReadAt(bytes, offset)
	if err != nil {
		return
	}
	d = bytes
	return
}
func (this *myDataFile) ReadV2() (rsn int64, d Data, err error) {

	//读取并更新偏移量
	var offset int64
	this.rMutex.Lock()
	offset = this.rOffset
	this.rOffset += int64(this.dataLen)
	this.rMutex.Unlock()

	//读取一个数据块
	rsn = offset / int64(this.dataLen)
	bytes := make([]byte, this.dataLen)
	for {
		this.fMutex.RLock()
		_, err = this.f.ReadAt(bytes, offset)
		if err != nil {
			if err == io.EOF {
				this.fMutex.RUnlock()
				continue
			}
			this.fMutex.RUnlock()
			return
		}
		d = bytes
		this.fMutex.RUnlock()
		return
	}
}

func (this *myDataFile) Read() (rsn int64, d Data, err error) {
	return this.ReadV2()
}

func (this *myDataFile) Write(d Data) (wsn int64, err error) {
	//读取并更新偏移量
	var offset int64
	this.wMutex.Lock()
	offset = this.wOffset
	this.wOffset += int64(this.dataLen)
	this.wMutex.Unlock()

	//写入一个数据块
	wsn = offset / int64(this.dataLen)
	var bytes []byte
	if len(d) > int(this.dataLen) {
		bytes = d[0:this.dataLen]
	} else {
		bytes = d
	}
	this.fMutex.Lock()
	defer this.fMutex.Unlock()
	_, err = this.f.Write(bytes)
	return
}

func (this *myDataFile) RSN() (rsn int64) {
	this.rMutex.Lock()
	defer this.rMutex.Unlock()
	return this.rOffset / int64(this.dataLen)
}

func (this *myDataFile) WSN() (wsn int64) {
	this.wMutex.Lock()
	defer this.wMutex.Unlock()
	return this.wOffset / int64(this.dataLen)
}

func (this *myDataFile) DataLen() uint32 {
	return this.dataLen
}

func (this *myDataFile) Close() error {
	if this.f != nil {
		return this.f.Close()
	}
	return nil
}
