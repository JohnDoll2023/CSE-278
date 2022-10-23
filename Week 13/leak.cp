// Program with memory leak
// Copyright 2020 geeksforgeeks.com

// function with memory leak 
void func_to_show_mem_leak() {
  int* ptr = new int(5);
  delete(ptr);
  return; 
} 

int main() { 
// Call the function to get the memory leak
  while (true) { 
    func_to_show_mem_leak(); 
  }

  return 0; 
}
