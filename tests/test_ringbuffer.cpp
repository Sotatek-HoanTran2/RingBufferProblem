#include <gtest/gtest.h>
extern "C" {
#include "ringbuffer.h"
}

TEST(RingBufferTest, BasicAddRemove) {
    ringbuffer_init(5);
    EXPECT_TRUE(ringbuffer_is_empty());
    EXPECT_EQ(0, ringbuffer_add(10));
    EXPECT_EQ(0, ringbuffer_add(20));
    EXPECT_FALSE(ringbuffer_is_empty());
    int v;
    EXPECT_EQ(0, ringbuffer_remove(&v));
    EXPECT_EQ(10, v);
    EXPECT_EQ(0, ringbuffer_remove(&v));
    EXPECT_EQ(20, v);
    EXPECT_EQ(1, ringbuffer_is_empty());
}

TEST(RingBufferTest, FullBehavior) {
    ringbuffer_init(3);
    EXPECT_EQ(0, ringbuffer_add(1));
    EXPECT_EQ(0, ringbuffer_add(2));
    EXPECT_EQ(0, ringbuffer_add(3));
    EXPECT_EQ(1, ringbuffer_is_full());
    EXPECT_EQ(-1, ringbuffer_add(4));
    int v;
    EXPECT_EQ(0, ringbuffer_remove(&v));
    EXPECT_EQ(1, v);
    EXPECT_EQ(0, ringbuffer_add(4)); 
    EXPECT_EQ(1, ringbuffer_is_full());
}
