#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "Printer.hpp"
#include "Multiton.hpp"

TEST (PrinterTest, LeasebyImportance) {
    typedef Multiton<Printer, Importance> multiton;
    auto main = multiton::get(Importance::primary);
    ASSERT_EQ (Printer::get_count(), 1) << "Only 1 printer should be created"; 
    auto aux1 = multiton::get (Importance::secondary);
    auto aux2 = multiton::get (Importance::secondary);
    ASSERT_EQ (Printer::get_count(), 2) << "Only 2 printer should be created";
    auto aux3 = multiton::get (Importance::tertiary);
    ASSERT_EQ (Printer::get_count(), 3) << "Only 3 printer should be created";
    auto aux4 = multiton::get (Importance::tertiary);
    ASSERT_EQ (Printer::get_count(), 3) << "Only 3 printer should be created";
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "Hello world" << std::endl;
  return RUN_ALL_TESTS();
}
