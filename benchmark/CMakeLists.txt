# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(demo_benchmark demo_benchmark.cpp )
add_executable(test_benches test_benches.cpp )
add_executable(test_benchmarks test_benchmarks.cpp)


# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(demo_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(test_benches PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(test_benchmarks PRIVATE project_paths project_warnings ${PROJECT_NAME})
