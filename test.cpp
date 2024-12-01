#include "custom_exceptions.h"

// Тестирование исключений
TEST(ExceptionTest, BaseException) {
    EXPECT_THROW(
        throw TMyException("Base exception"),
        TMyException
    );
}

TEST(ExceptionTest, DerivedException1) {
    EXPECT_THROW(
        throw DerivedException1("Derived exception 1"),
        DerivedException1
    );
}

TEST(ExceptionTest, DerivedException2) {
    EXPECT_THROW(
        throw DerivedException2("Derived exception 2"),
        DerivedException2
    );
}

TEST(ExceptionTest, ExceptionMessage) {
    try {
        TMyException ex("Error: ");
        ex << "additional details.";
        throw ex;
    }
    catch (const TMyException& e) {
        EXPECT_STREQ(e.what(), "Error: additional details.");
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}