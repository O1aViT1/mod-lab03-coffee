// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata_tests, test_initial) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(automata_tests, test_on) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(automata_tests, test_off) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(automata_tests, test_coin) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(automata_tests, test_choice) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(automata_tests, test_check_money) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(0);
    EXPECT_TRUE(a.check());
}

TEST(automata_tests, test_check_fail) {
    Automata a;
    a.on();
    a.coin(5); 
    a.choice(0);
    EXPECT_FALSE(a.check());
}

TEST(automata_tests, test_cook) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.cook();
    EXPECT_EQ(a.getState(), COOK);
}

TEST(automata_tests, test_finish) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(1);
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(automata_tests, test_cancel) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(automata_tests, test_cancel_check) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}
