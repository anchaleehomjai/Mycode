// // อัญชลี หอมใจ
// // 6405010690
// // Lab05_1
// // 204203 Sec 001
// curl localhost:3333
package main
import (
	"errors"
	"fmt"
	"io"
	"net/http"
	"os"
)
func main() {
	
	// http.HandleFunc("/", getRoot)
	// http.HandleFunc("/hello", getHello)
	mux := http.NewServeMux()
	mux.HandleFunc("/", getRoot)
	mux.HandleFunc("/hello", getHello)

	err := http.ListenAndServe(":3333", mux)
	if errors.Is(err, http.ErrServerClosed) {
		fmt.Printf("server closed\n")
	} else if err != nil {
		fmt.Printf("error starting server: %s\n", err)
		os.Exit(1)
	}
}

	func getRoot(w http.ResponseWriter, r *http.Request) {
		fmt.Printf("got / request\n")
		io.WriteString(w, "This is my website!\n")
	}

	func getHello(w http.ResponseWriter, r *http.Request) {
		fmt.Printf("got /hello request\n")
		io.WriteString(w, "Hello, HTTP!\n")
	}
