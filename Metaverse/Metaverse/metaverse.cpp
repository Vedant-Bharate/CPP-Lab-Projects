#include "metaverse.h"
#include "display.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <vector>

/*
 * count_neighbors()
 *
 * Counts number of neighboring cell with value 1
 *
 * input: board - The entire metaverse board
 *        row - row index to check which neighbors to count
 *        columns - column index to check which neighbors to count
 *
 * output: Returns the count of neighboring cells with the value 1
 */
int count_neighbors(const metaverse_t &board, int row, int column) {

    std::vector<std::vector<int>> directions{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    int count = 0;

    for (const auto& direction : directions)
    {
        int new_row = row + direction[0];
        int new_col = column + direction[1];

        if (new_row >= 0 && new_row < board.size() && new_col >= 0 && new_col < board[0].size()) {
            if (board[new_row][new_col] == 1) {
                count++;
            };
        }
    }
    return count;

  return 0;
}

/*
 * occupied_in_next_tick
 *
 * This function checks if a neighboring cell will be occupied in the next tick
 *
 * input: currently_occupied - Current state of the cell (Checks if occupied or unoccupied)
 *        neighbor_count - number of neighbor
 * output: returns True if the cell will be occupied in the next tick, otherwise false.
 */
bool occupied_in_next_tick(bool currently_occupied, int neighbor_count) {

    if (currently_occupied == 1 && (neighbor_count == 2 || neighbor_count == 3)) {
        return true;
    }
    else if (currently_occupied == 0 && neighbor_count == 3) {
        return true;
    }

  return false;
}

/*
 * metaverse_t tick()
 *
 * This function creates a new metaverse for the next tick.
 *
 * input: board - The entire metaverse board
 * output: Returns the new board of metaverse for the next tick
 */
metaverse_t tick(const metaverse_t &board) {

    metaverse_t NEW;
    resize_metaverse(board.size(), NEW);
    for (int i = 0; i < NEW.size(); i++) {
        for (int j = 0; j < NEW[i].size(); j++)
        {
            int neighbor_count = count_neighbors(board, i, j);
            NEW[i][j] = occupied_in_next_tick(board[i][j], neighbor_count);
        }
    }
    return NEW;
}

/*
 * resize_metaverse()
 *
 * This function resizes current metaverse to given parameters
 *
 * input: rows - Number of rows the new metaverse needs to be
 *        board - Current metaverse board
 * output: Returns TRUE if current board was successfully resized, otherwise returns FALSE
 */
bool resize_metaverse(int rows, metaverse_t &board) {

    board.resize(rows);
    for (auto& column : board) {
        column.resize(rows);
    }
    return true;

}

/*
 * citizenship_row_to_metaverse_row()
 *
 * This function converts a citizenship row to a metaverse row
 *
 * input: input_row - String representing citizenship row
 *        row - Index for row in metaverse
 * output: Returns TRUE if citizenship row is successfully converted to metaverse row
 */
bool citizenship_row_to_metaverse_row(const std::string &input_row, int row,
                                      metaverse_t &board) {

    for (int Index_String = 0; Index_String < input_row.size(); Index_String++) {
        if (input_row[Index_String] == '1') {
            board[row][Index_String] = 1;
        }
        else if (input_row[Index_String] == '0') {
            board[row][Index_String] = 0;
        }
        else {
            return false;
        }
    }
    return true;

}

/*
 * read_metaverse_configuration_line_from_file()
 *
 * This functions reads a file to check metaverse board configuration, extracts size and generations value
 *
 * input: File - metaverse_file: Input file consisting of metaverse configuration and values
 *               size - Variable to store the size value from config file
 *               generations - Variable to store the generational values from config file
 * output: Returns TRUE if file was read successfully, otherwise returns FALSE
 */
bool read_metaverse_configuration_line_from_file(std::ifstream &metaverse_file,
                                                 int &size, int &generations) {
  
    char comma;
    if ((metaverse_file >> size) && (metaverse_file >> comma) && (metaverse_file >> generations)) {
        return true;
    }
    return false;

}

/*
 * bool initialize_metaverse_from_file()
 *
 * Reads metaverse config file and initializes a metaverse according to the constraints
 *
 * input: metaverse_file - Input file consisting of metaverse configuration and values
 *        metaverse - metaverse that needs to be initialized
 *        generations - Variable to store the generational values from config file
 * output: Returns TRUE if metaverse is initialized, otherwise returns FALSE
 */
bool initialize_metaverse_from_file(std::ifstream &metaverse_file,
                                    metaverse_t &metaverse,
                                    int &generations) {
  int size{};
  int actual_row{};

  generations = 0;

  if (!read_metaverse_configuration_line_from_file(metaverse_file, size,
                                                   generations)) {
    return false;
  }

  if (!resize_metaverse(size, metaverse)) {
    return false;
  }

  metaverse_file >> std::ws;
  while (!metaverse_file.eof()) {
    std::string line{};
    if (!std::getline(metaverse_file, line)) {
      return false;
    }
    if (!citizenship_row_to_metaverse_row(line, actual_row, metaverse)) {
      return false;
    }
    actual_row++;
    metaverse_file >> std::ws;
  }
  return actual_row == size;
}

/*
 * model_metaverse()
 *
 * This functions simulates the evolution of a metaverse, represented by a TICK 
 *
 * input: starting_metaverse - The starting/initial metaverse to start the simulation from
 *        generations - Variable to store the generational values from config file
 * output: NONE - Since function is initialized with void
 */
void model_metaverse(const metaverse_t &starting_metaverse, int generations) {

    metaverse_t current_metaverse = starting_metaverse;
    for (int i = 0; i < generations; i++) {
        display_metaverse(std::cout, current_metaverse);
        current_metaverse = tick(current_metaverse);

    }

}
