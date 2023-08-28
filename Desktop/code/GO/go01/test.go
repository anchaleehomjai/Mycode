package main

func power(x uint64) bool {
	if x&(x-1) == 0 {
		return true
	} else {
		return false
	}
}
