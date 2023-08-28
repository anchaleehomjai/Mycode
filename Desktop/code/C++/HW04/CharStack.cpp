class CharStack {

public:


  char stack[10];
  char stacktop;
  int item;
  CharStack() { // constructor
  item = -1;
  }
  void push(char new_item) {
      item++;
      stack[item] = new_item;
      
  }

  char pop() {
      stacktop = stack[item];
      item--;
      return stacktop;

    }

  char top() {

    stacktop = stack[item];
    return stacktop;

  }

  bool isEmpty() {
    if(item == -1 )
      return true;
    else{
      return false;
    }

  }
};