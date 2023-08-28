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
	// listen on part 8000
	ln, err := net.Listen("tcp", ":8000")
	check(err, "Server is ready.")

	for{
		conn, err := ln.Accept()
		check(err, "Accepted connection.")
	go func(msg string) {
		for{
			client := bufio.NewReader(conn)
			message,err := client.ReadString('\n')
			if err != nil{
				fmt.Print("Client disconected.\n")
				break
			}else{
				fmt.Print("Message Received: ", string(message))
				fmt.Print("Text to send: ")
				reader := bufio.NewReader(os.Stdin)
				text, _ := reader.ReadString('\n')
				// send to server
				fmt.Fprintf(conn, text + "\n")
			}
		}
	}("going")
}
}