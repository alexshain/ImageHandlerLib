cmake_minimum_required(VERSION 3.29)

project(quasi-one-dimensional LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Исполняемый файл с указанием исходных файлов
add_executable(Executable 
			src/work_with_images/main.cpp
			src/work_with_images/consoleApplicationImageOperation.cpp
			src/work_with_images/file_operations.cpp
			src/work_with_images/image_handler/factory/imageHandlerFactory.cpp 
			src/work_with_images/image_handler/addWallsHandler.cpp 
			src/work_with_images/image_handler/cutOutAreaHandler.cpp 
			src/work_with_images/image_handler/removeClosedPoresHandler.cpp 
			src/work_with_images/image_handler/slice3DImage.cpp
			src/work_with_images/standard_image_lib/factory/standardImageFactory.cpp
			src/work_with_images/standard_image_lib/circle.cpp
			src/work_with_images/standard_image_lib/sinusoidalChannel.cpp
			src/work_with_images/standard_image_lib/twoChannels.cpp
			src/work_with_images/standard_image_lib/standardImage.cpp)

# Исполняемый файл с указанием исходных файлов
add_executable(SolutionSlau src/slau/main.cpp
				src/slau/DenseMatrix.cpp
				src/slau/Band5Matrix.cpp 
				src/slau/SolverSlau.cpp
				src/slau/LeastResidualMethod.cpp)
