bool is_can_exit_from_maze(std::vector<std::string> maze, int r, int c) {
    if (maze[r][c] == 'E')return true;
    if (maze[r][c] == '#')return false;
    maze[r][c] = '#';
    return is_can_exit_from_maze(maze, r + 1, c) || is_can_exit_from_maze(maze, r - 1, c) || is_can_exit_from_maze(maze, r, c + 1) || is_can_exit_from_maze(maze, r, c - 1);
}
