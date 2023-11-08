package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Task struct {
	UserID    int    `json:"user_id"`
	ID        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

type Project struct {
	ProjectID int    `json:"project_id"`
	Tasks     []Task `json:"tasks"`
}

func main() {
	var userID int
	fmt.Scan(&userID)

	file, err := os.ReadFile("data.json")
	if err != nil {
		fmt.Println("Ошибка чтения файла:", err)
		return
	}

	var projects []Project
	err = json.Unmarshal(file, &projects)
	if err != nil {
		fmt.Println("Ошибка парсинга JSON данных:", err)
		return
	}

	completedTasks := 0
	for _, project := range projects {
		for _, task := range project.Tasks {
			if task.UserID == userID && task.Completed {
				completedTasks++
			}
		}
	}

	fmt.Println(completedTasks)
}
