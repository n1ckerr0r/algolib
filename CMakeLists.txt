cmake_minimum_required(VERSION 3.20)

project(algolib
        VERSION 0.1.0
        DESCRIPTION "Header-only C++ Algorithms and Data Structures Library"
        LANGUAGES CXX
)

add_library(algolib INTERFACE)

target_include_directories(algolib
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(algolib INTERFACE cxx_std_20)

# Подключение модуля для стандартных путей для установки
include(GNUInstallDirs)

# Копирование папки include/ в системную дирикторию для заголовков
install(
        DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Установка библиотеки и создание экспорта
install(
        TARGETS algolib
        EXPORT algolibTargets
)

# Установка файла экспорта с информацией о библиотеке
# Создание файла algolibTargets.cmake с пространством имен algolib::
install(
        EXPORT algolibTargets
        FILE algolibTargets.cmake
        NAMESPACE algolib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/algolib
)

# Подключение помошника для создания конфигурационных файлов
include(CMakePackageConfigHelpers)

# Создание файла для проверки версии библиотеки
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/algolibConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion  # Только совместимые мажорные версии
)

# Создание финального файла конфигурации на основе шаблона
configure_package_config_file(
        cmake/algolibConfig.cmake.in  # Шаблон конфига
        "${CMAKE_CURRENT_BINARY_DIR}/algolibConfig.cmake"  # Итоговый файл
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/algolib
)

# Устанановка конфигурационных файлов пакета
# Копирование созданных файлов в системную директорию
install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/algolibConfig.cmake" # Основной конфиг
        "${CMAKE_CURRENT_BINARY_DIR}/algolibConfigVersion.cmake" # Файл версии
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/algolib
)
