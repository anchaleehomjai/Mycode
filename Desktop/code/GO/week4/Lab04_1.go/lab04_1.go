package main

type Node struct{
	val int
	left *Node
	right *Node
}
type BTree struct{
	root *Node
}

v:= 4
t := &BSTadd



func (t *BTree) BSTadd(v int) *BTreer {
	if v <= t.root.val {
		if t.root == nil {
			t.root = &Node{val: v, left: nil, right: nil}
		} else {
			t.root.left.Nodeadd(v)
		}
	} else {
		if t.root == nil {
			t.root = &Node{val: v, left: nil, right: nil}
		} else {
			t.root.right.Nodeadd(v)
		}
	}
	return t
}
func (node *Node) Nodeadd(v int){
	if root is None
		t



}

func main() {
	tree := &BTree{}
	list := [7]int{4, 6, 2, 30, 1, 3, 18}


}
