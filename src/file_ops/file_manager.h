#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <optional>
#include <filesystem>

class file_manager {
    std::filesystem::path temp_dir_path;
    bool is_valid_file(std::filesystem::path path);

public:
    file_manager(std::filesystem::path temp_dir_path);
    bool set_temp_dir_path(std::filesystem::path new_path);
    bool move_file_to(std::filesystem::path file, std::filesystem::path path);
    bool move_file_to_temp(std::filesystem::path file);
    std::optional<std::filesystem::path> get_file_from_temp(std::string file_name);
};

#endif