#include <gtest/gtest.h>
#include "../src/simpleQueue.h"


TEST(QueueTestSuite, testSizeQueue) {
    simpleQueue::MySimpleQueue<int> q{};
    q.push(1);
    q.push(1);
    q.push(1);
    EXPECT_EQ(3, q.size());
}

TEST(QueueTestSuite, testIsEmptyQueue) {
    simpleQueue::MySimpleQueue<int> q{};
    EXPECT_TRUE(q.isEmpty());
}

TEST(QueueTestSuite, testFirstElemQueue) {
    simpleQueue::MySimpleQueue<int> q{};
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    EXPECT_EQ(1, q.first());
}

TEST(QueueTestSuite, testBackElemQueue) {
    simpleQueue::MySimpleQueue<int> q{};
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    EXPECT_EQ(5, q.back());
}

TEST(QueueTestSuite, testPushQueue) {
    simpleQueue::MySimpleQueue<int> q{};
    int elem = 5;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(elem);

    EXPECT_EQ(elem, q.back());
}

TEST(QueueTestSuite, testPopQueue) {
    simpleQueue::MySimpleQueue<int> q{};
    int elem = 1;
    q.push(elem);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    EXPECT_EQ(elem, q.pop());
}
