package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	
	
)

func check(err error, message string){
	if err != nil{
		panic(err)
	}
	fmt.Printf("%s\n", message)
}

func main() {
	fmt.Println("Start server...")

	// listen on part 8000
	ln, err := net.Listen("tcp", ":8000")
	check(err, "Server is ready.")

	// accept connection
	conn, err := ln.Accept()
	check(err, "Accepted connection.")

	//run loop forever (or until ctrl - c)
	for{
		// create buffer and recive from conn
		client := bufio.NewReader(conn)
		message, _ := client.ReadString('\n')
		fmt.Print("Message Received:", string(message))
		fmt.Print("Text to send: ")

		// create buffer to get keyboard input
		keyboard_buffer := bufio.NewReader(os.Stdin)
		text, _ := keyboard_buffer.ReadString('\n')
		// send to server
		fmt.Fprintf(conn, text + "\n")
	}
}