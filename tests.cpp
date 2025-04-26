#include <string>

#include "main.h"

#include "cute/cute.h"
#include "cute/ide_listener.h"
#include "cute/cute_runner.h"

using namespace std;

void test_is_correct_EMPTY() {
    const string s;
    constexpr bool expected = false;
    const bool actual = is_correct(s);

    ASSERT_EQUAL(expected, actual);
}

void test_is_correct_SEMI_STRING() {
    const string s = "-21uwu";
    constexpr bool expected = false;
    const bool actual = is_correct(s);

    ASSERT_EQUAL(expected, actual);
}

void test_is_correct_NUMBER() {
    const string s = "102";
    constexpr bool expected = true;
    const bool actual = is_correct(s);

    ASSERT_EQUAL(expected, actual);
}


void test_get_reminder() {
    constexpr int a = 12;
    constexpr int b = 6;
    constexpr int expected = 0;
    const int actual = get_reminder(a, b);

    ASSERT_EQUAL(expected, actual);
}


void test_get_division() {
    constexpr int a = 6;
    constexpr int b = 12;
    constexpr int expected = 2;
    const int actual = get_division(a, b);

    ASSERT_EQUAL(expected, actual);
}


int launch_tests() {
    cute::suite s;

    s.emplace_back(test_is_correct_EMPTY);
    s.emplace_back(test_is_correct_SEMI_STRING);
    s.emplace_back(test_is_correct_NUMBER);
    s.emplace_back(test_get_reminder);
    s.emplace_back(test_get_division);

    cute::ide_listener<> listener;
    return makeRunner(listener)(s, "All my task tests");
}
