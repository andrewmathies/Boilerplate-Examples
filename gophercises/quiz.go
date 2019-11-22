package main

import (
  "fmt"
  "bufio"
  "encoding/csv"
  "io/ioutil"
  "strings"
  "strconv"
  "os"
  "flag"
)

// https://github.com/gophercises/quiz

func check(e error) {
  if e != nil {
    panic(e)
  }
}

func main() {
  var filename = flag.String("file", "enter the csv file with quiz questions and answers")
  flag.Parse()

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
  stdinReader := bufio.NewReader(os.Stdin)
  
  var total int
  correct := 0
  
  for i, line := range(lines) {
    if len(line) != 2 {
      fmt.Println("ERR, line doesn't have two elements")
      fmt.Println(line)
      return
    }

    fmt.Println(line[0])

    userVal, err := stdinReader.ReadString('\n')
    userVal = strings.Replace(userVal, "\n", "", -1)
    check((err))

    userAnswer, err := strconv.Atoi(userVal)

    answer, err := strconv.Atoi(line[1])
    check(err)

    if answer == userAnswer {
      correct++
    }
    total = i + 1
  }

  fmt.Println("you got", correct, "out of", total, "correct")
}