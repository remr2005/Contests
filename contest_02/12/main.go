func IsPosit(a int) int {
	if a == -1 {
		return 0
	}
	return 1
}
func fill(maze [][]int) {
	for i := 0; i < len(maze); i++ {
		for j := 0; j < len(maze[0]); j++ {
			if maze[i][j] == -1 {
				if i == 0 {
					if j == 0 {
						maze[i+1][j] += IsPosit(maze[i+1][j])
						maze[i+1][j+1] += IsPosit(maze[i+1][j+1])
						maze[i][j+1] += IsPosit(maze[i][j+1])
					} else if j == len(maze[0])-1 {
						maze[i+1][j] += IsPosit(maze[i+1][j])
						maze[i+1][j-1] += IsPosit(maze[i+1][j-1])
						maze[i][j-1] += IsPosit(maze[i][j-1])
					} else {
						maze[i+1][j] += IsPosit(maze[i+1][j])
						maze[i+1][j+1] += IsPosit(maze[i+1][j+1])
						maze[i+1][j-1] += IsPosit(maze[i+1][j-1])
						maze[i][j+1] += IsPosit(maze[i][j+1])
						maze[i][j-1] += IsPosit(maze[i][j-1])
					}
				} else if i == len(maze)-1 {
					if j == 0 {
						maze[i][j+1] += IsPosit(maze[i][j+1])
						maze[i-1][j+1] += IsPosit(maze[i-1][j+1])
						maze[i-1][j] += IsPosit(maze[i-1][j])
					} else if j == len(maze[0])-1 {
						maze[i][j-1] += IsPosit(maze[i][j-1])
						maze[i-1][j] += IsPosit(maze[i-1][j])
						maze[i-1][j-1] += IsPosit(maze[i-1][j-1])
					} else {
						maze[i-1][j] += IsPosit(maze[i-1][j])
						maze[i-1][j-1] += IsPosit(maze[i-1][j-1])
						maze[i-1][j+1] += IsPosit(maze[i-1][j+1])
						maze[i][j+1] += IsPosit(maze[i][j+1])
						maze[i][j-1] += IsPosit(maze[i][j-1])
					}
				} else if j == 0 {
					maze[i-1][j] += IsPosit(maze[i-1][j])
					maze[i+1][j] += IsPosit(maze[i+1][j])
					maze[i-1][j+1] += IsPosit(maze[i-1][j+1])
					maze[i][j+1] += IsPosit(maze[i][j+1])
					maze[i+1][j+1] += IsPosit(maze[i+1][j+1])
				} else if j == len(maze[0])-1 {
					maze[i-1][j] += IsPosit(maze[i-1][j])
					maze[i+1][j] += IsPosit(maze[i+1][j])
					maze[i-1][j-1] += IsPosit(maze[i-1][j-1])
					maze[i][j-1] += IsPosit(maze[i][j-1])
					maze[i+1][j-1] += IsPosit(maze[i+1][j-1])
				} else {
					maze[i-1][j] += IsPosit(maze[i-1][j])
					maze[i-1][j+1] += IsPosit(maze[i-1][j+1])
					maze[i-1][j-1] += IsPosit(maze[i-1][j-1])
					maze[i+1][j] += IsPosit(maze[i+1][j])
					maze[i+1][j+1] += IsPosit(maze[i+1][j+1])
					maze[i+1][j-1] += IsPosit(maze[i+1][j-1])
					maze[i][j-1] += IsPosit(maze[i][j-1])
					maze[i][j+1] += IsPosit(maze[i][j+1])
				}
			}
		}
	}
}