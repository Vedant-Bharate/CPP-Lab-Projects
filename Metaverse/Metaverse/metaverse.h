#ifndef __METAVERSE_H
#define __METAVERSE_H
#include <fstream>
#include <vector>
#include <string>

using metaverse_t = std::vector<std::vector<bool>>;

int count_neighbors(const metaverse_t &board, int row, int column);

bool occupied_in_next_tick(bool currently_occupied, int neighbor_count);

metaverse_t tick(const metaverse_t &board);

bool resize_metaverse(int rows, metaverse_t &board);

bool citizenship_row_to_metaverse_row(const std::string &input_row, int row,
                            metaverse_t &board);

bool read_metaverse_configuration_line_from_file(std::ifstream &metaverse_file, int &size,
                               int &generations);
bool initialize_metaverse_from_file(std::ifstream &metaverse_file,
                                    metaverse_t &metaverse, int &generations);

void model_metaverse(const metaverse_t &metaverse, int generations);

#endif
