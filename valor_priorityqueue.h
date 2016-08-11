#ifndef VALOR_PRIORITYQUEUE
#define VALOR_PRIORITYQUEUE

#include <algorithm>
#include <functional>
#include <vector>

namespace valor {

///
/// Priority queue implementation with more functionality than std::priority_queue,
/// for ease of use in A* search.
///
template <
  typename ValueType,
  typename PriorityComparator = std::less<ValueType>,
  typename SearchComparator = std::less<ValueType>
>
class PriorityQueue {
public:
  template <typename ... Arguments>
  void emplace (Arguments && ... arguments) {
    data_.emplace_back(std::forward<Arguments>(arguments) ...);
    std::push_heap(data_.begin(), data_.end(), PriorityComparator());
  }

  const ValueType & top () const {
    return data_.front();
  }

  void pop () {
    std::pop_heap(data_.begin(), data_.end(), PriorityComparator());
    data_.pop_back();
  }

  bool contains (
    const ValueType & value,
    const std::function<bool(const ValueType &, const ValueType &)> & comparator = SearchComparator()
  ) const {
    return std::find_if(data_.begin(), data_.end(), [&] (const ValueType & current) {
      return !(comparator(current, value) || comparator(value, current));
    }) != data_.end();
  }

  void erase (
    const ValueType & value,
    const std::function<bool(const ValueType &, const ValueType &)> & comparator = SearchComparator()
  ) {
    data_.erase(std::remove_if(data_.begin(), data_.end(), [&] (const ValueType & current) {
      return !(comparator(current, value) || comparator(value, current));
    }), data_.end());
    std::make_heap(data_.begin(), data_.end(), PriorityComparator());
  }

  std::size_t size () const {
    return data_.size();
  }

  bool empty () const {
    return data_.empty();
  }

private:
  std::vector<ValueType> data_;
};

}

#endif
