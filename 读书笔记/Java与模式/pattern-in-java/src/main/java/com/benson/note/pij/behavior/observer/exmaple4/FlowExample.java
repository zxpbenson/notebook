package com.benson.note.pij.behavior.observer.exmaple4;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.concurrent.Flow;
import java.util.concurrent.SubmissionPublisher;

public class FlowExample {

    private static final Logger LOG = LoggerFactory.getLogger(FlowExample.class);

    /*
     * Java 9 引入了 Flow API，用于支持响应式编程。
     * 提供了异步、非阻塞的数据流处理机制，主要用于构建基于 发布-订阅（Publisher-Subscriber） 模型的并发数据处理框架。
     * Flow API 中的核心接口有：
     * 1. Flow.Publisher<T>（发布者）
     * 2. Flow.Subscriber<T>（订阅者）
     * 3. Flow.Subscription（订阅）
     * 4. Flow.Processor<T, R>（处理器）
     *
     * Flow 主要用于 异步数据流处理，可用于：
     * 流式处理：数据按流的方式传输，避免一次性加载大量数据导致的内存占用问题。
     * 背压（Backpressure）控制：消费者（Subscriber）可以控制数据的消费速度，避免被生产者（Publisher）压垮。
     * 并发与异步：支持并行计算、非阻塞数据传输，提高性能。
     *
     * */

    public static void main(String[] args) throws InterruptedException {
        // 创建一个发布者
        SubmissionPublisher<String> publisher = new SubmissionPublisher<>();

        // 创建一个订阅者
        Flow.Subscriber<String> subscriber = new Flow.Subscriber<>() {
            private Flow.Subscription subscription;

            @Override
            public void onSubscribe(Flow.Subscription subscription) {
                this.subscription = subscription;
                LOG.info("订阅者已订阅");
                subscription.request(1); // 申请1个数据项
            }

            @Override
            public void onNext(String item) {
                LOG.info("接收到数据: " + item);
                subscription.request(1); // 继续请求下一个数据项
            }

            @Override
            public void onError(Throwable throwable) {
                LOG.error("发生错误: ", throwable.getMessage());
            }

            @Override
            public void onComplete() {
                LOG.info("数据接收完成");
            }
        };

        // 订阅者订阅发布者
        publisher.subscribe(subscriber);

        // 发送数据
        LOG.info("发布数据: Hello");
        publisher.submit("Hello");

        LOG.info("发布数据: World");
        publisher.submit("World");

        // 关闭发布者
        //publisher.close();

        // 等待数据处理完成
        Thread.sleep(3000);
    }
}
