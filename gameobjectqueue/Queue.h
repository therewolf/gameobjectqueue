#pragma once
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>
#include <queue>

template <typename T>
class Queue
{
public:
	Queue() = default;
	Queue(const Queue&) = delete; // Not copyable
	Queue &operator=(const Queue&) = delete; //Not assignable

	T pop()
	{
		std::unique_lock<std::mutex> locker(mutex_);
		cond_.wait(locker, [&](){ return !queue_.empty(); });
		auto item = queue_.front();
		queue_.pop();
		return item;
	}

	void push(const T& item)
	{
		std::unique_lock<std::mutex> locker(mutex_);
		queue_.push(item);
		locker.unlock();
		cond_.notify_one();
	}

private:
	std::queue<T> queue_;
	std::mutex mutex_;
	std::condition_variable cond_;
};

// Explicit instatiation for Object*
	template class Queue<Object*>;