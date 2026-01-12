#include "./file_manager.h"

#include <filesystem>
#include <optional>

file_manager::file_manager(std::filesystem::path temp_dir_path){
    this->temp_dir_path = temp_dir_path;
}

bool file_manager::is_valid_file(std::filesystem::path path)
{
    if ( !std::filesystem::exists(path) ){
        return false;
    }

    if ( !std::filesystem::is_directory(path) ){
        return false;
    }

    return true;
}

bool file_manager::set_temp_dir_path(std::filesystem::path new_path){
    if( !std::filesystem::is_directory(new_path) ){
        return false;
    }

    this->temp_dir_path = new_path;
    return true;
}

bool file_manager::move_file_to(std::filesystem::path file, std::filesystem::path path){
    if( !this->is_valid_file(file) ){
        return false;
    }

    // TODO: Logic to move file to directory

    return true;
}

bool file_manager::move_file_to_temp(std::filesystem::path file){
    if( !is_valid_file(file) ){
        return false;
    }

    return this->move_file_to(file, this->temp_dir_path);
}

std::optional<std::filesystem::path> file_manager::get_file_from_temp(std::string file_name){
    std::optional<std::filesystem::path> result;

    auto file_path = this->temp_dir_path.append(file_name);
    if( is_valid_file(file_path) ){
        result = file_path;
    }

    return result;
}