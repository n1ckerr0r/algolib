include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        # Чтобы убрать предупреждение, сохраняет оригинальные временые метки
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Скачивание GoogleTest
FetchContent_MakeAvailable(googletest)

add_executable(test_selection_sort
        test_selection_sort.cpp
)

# Подключение тестов
target_link_libraries(test_selection_sort
        PRIVATE
        algolib
        GTest::gtest_main
)

include(GoogleTest)
# Поиск тестов
gtest_discover_tests(test_selection_sort)
