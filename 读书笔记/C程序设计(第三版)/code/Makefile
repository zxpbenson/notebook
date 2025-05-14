PROGS03 = 03_02 03_03 03_04
PROGS07 = 07_09
PROGS = $(PROGS03) $(PROGS07)  # 合并各个章节

all: $(PROGS)  # 所有章节示例

%: %.c        # 隐含规则：从同名 .c 文件编译可执行文件
	$(CC) $< -o $@

clean:
	rm -f $(PROGS)  # 正确删除所有目标文件

