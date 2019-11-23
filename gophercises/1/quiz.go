package main

import (
	"bufio"
	"encoding/csv"
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
	"time"
)

// https://github.com/gophercises/quiz

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func readCSV(filename *string) ([]string, []int) {
	var fileData []byte
	var err error

	if *filename == "" {
		fileData, err = ioutil.ReadFile("problems.csv")
	} else {
		fileData, err = ioutil.ReadFile(*filename)
	}

	check(err)
	fileText := string(fileData)

	reader := csv.NewReader(strings.NewReader(fileText))
	lines, err := reader.ReadAll()
	check(err)

	questions := make([]string, 0)
	answers := make([]int, 0)

	for _, line := range lines {
		questions = append(questions, line[0])
		answer, err := strconv.Atoi(line[1])
		check(err)
		answers = append(answers, answer)
	}

	return questions, answers
}

func getInput(ch chan int, questions []string) {
	stdinReader := bufio.NewReader(os.Stdin)

	for _, question := range questions {
		fmt.Println(question)

		userVal, err := stdinReader.ReadString('\n')

		if err != nil {
			close(ch)
			return
		}

		userVal = strings.Replace(userVal, "\n", "", -1)
		check(err)
		userAnswer, _ := strconv.Atoi(userVal)

		ch <- userAnswer
	}

	close(ch)
}

func main() {
	var filename = flag.String("file", "", "Supply the csv filename with quiz questions and answers.")
	var totalTime = flag.Int("time", 30, "Supply the time desired until the quest ends.")
	flag.Parse()

	questions, answers := readCSV(filename)

	fmt.Println("You have", *totalTime, "seconds to complete the quiz. Press enter when you are ready to begin.")
	bufio.NewReader(os.Stdin).ReadBytes('\n')

	ch := make(chan int)
	go getInput(ch, questions)

	timer := time.NewTimer(time.Duration(*totalTime) * time.Second)
	total := len(questions)
	correct := 0

loop:
	for i := 0; i < total; i++ {
		select {
		case userAnswer, ok := <-ch:
			if !ok {
				break loop
			}
			if userAnswer == answers[i] {
				correct++
			}
		case <-timer.C:
			fmt.Println("Time is up.")
			break loop
		}
	}

	fmt.Println("Score:", correct, "/", total)
}
