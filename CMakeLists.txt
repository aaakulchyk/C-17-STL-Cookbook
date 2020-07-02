cmake_minimum_required(VERSION 3.16)
project(C__17_STL_Cookbook)

set(CMAKE_CXX_STANDARD 17)

add_executable(C__17_STL_Cookbook main.cc

        stl_containers/vector_access.h
        stl_containers/keep_vector_sorted.h
        stl_containers/inserting_into_map.h
        stl_containers/map_insertion_hint_semantics.h
        stl_containers/efficiently_modifying_map.h
        stl_containers/unordered_map_with_custom_types.h
        stl_containers/filtering_duplicates.h
        stl_containers/rpn_calculator.h
        stl_containers/word_frequency_counter.h
        stl_containers/writing_style_helper.h
        stl_containers/personal_todo_list.h

        iterators/iterable_range.h
        iterators/iterator_categories.h
        iterators/iterator_adapters.h
        iterators/iterator_algorithms.h
        iterators/reverse_iterator_adapters.h
        iterators/iterator_sentinels.h
        iterators/checked_iterators.h
        iterators/zip_iterator.h

        lambda_expressions/defining_lambdas.h
        lambda_expressions/wrapping_lambdas.h
        lambda_expressions/function_concatenation.h
        lambda_expressions/complex_predicates.h
        lambda_expressions/multifunction_calling.h)
