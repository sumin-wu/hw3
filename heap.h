#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <vector>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  PComparator pc;
  std::vector<T> heap;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): m_(m), pc(c)
{

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  //delete heap;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heap.push_back(item);//then move item into right place
 
  //last element we just added index:
  int idx = heap.size()-1;
  while (idx>0)
  {
     //find parent index
    //(idx-1)/m_
    //heapify up
    int pIdx= (idx-1)/m_;
    if (pc(heap[pIdx],heap[idx])==false){//if node order not at the right place..
      std::swap(heap[idx],heap[pIdx]);
      idx=pIdx;//index update
    }
    else{
      break;
    }
  }
}


  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heap.size()==0;
}

    /**
   * @brief Returns size of the heap
   * 
   */
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return heap.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");

  }
  int idx = (int)heap.size()-1; //idx of last item
  std::swap(heap[idx],heap[0]); //swap top and last item
  heap.pop_back();
  idx=0;//heapify down the first item
  while (idx<(int)heap.size()){
    int best_c = m_*idx+1; 
  // children is at m*n + i
    //find top priority children to swap
    for (int i =1; i<=m_; i++)
    {
      if (m_*idx+i>(int)heap.size()-1)
      {
        break;
      }
      else{
        if(pc(heap[m_*idx+i],heap[best_c])){
          best_c=m_*idx+i;
        }
      }
    }
    if (best_c>(int)heap.size()-1 || heap[best_c]==heap[idx])
    {
      break;
    }
    
    if (pc(heap[best_c],heap[idx]))
    {
      std:: swap(heap[best_c],(heap[idx]));
      idx = best_c;
    }
    else{
      break;
    }
}
}



#endif

