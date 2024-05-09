#ifndef _Joining_Thread
#define _Joining_Thread
#include <thread>
#include <utility>
class joining_thread
{
public:
	joining_thread() noexcept = default;
	template<typename Callable, typename ...Args>
	explicit joining_thread(Callable&& funct, Args&&... args) : t(std::forward<Callable>(funct), std::forward<Args>(args)...)
	{
		// do nothing
	}
	explicit joining_thread(std::thread _t) noexcept : t(std::move(_t)) {}
	joining_thread(joining_thread&& other) noexcept : t(std::move(other.t)) {}
	joining_thread& operator= (joining_thread&& other) noexcept;
	joining_thread& operator= (std::thread other) noexcept;
	~joining_thread();
	void swap(joining_thread& other);
	std::thread::id get_id() const noexcept;
	bool joinable() const noexcept;
	void join();
	void detach();

private:
	std::thread t;
};


inline joining_thread& joining_thread::operator=(joining_thread&& other) noexcept
{
	if (joinable() == true)
	{
		join();
	}
	t = std::move(other.t);
	return *this;
}

inline joining_thread& joining_thread::operator=(std::thread other) noexcept
{
	if (joinable() == true)
	{
		join();
	}
	t = std::move(other);
	return *this;
}

inline joining_thread::~joining_thread()
{
	if (joinable() == true)
	{
		join();
	}
}

inline void joining_thread::swap(joining_thread& other)
{
	t.swap(other.t);
}

inline std::thread::id joining_thread::get_id() const noexcept
{
	return t.get_id();
}

inline bool joining_thread::joinable() const noexcept
{
	return t.joinable();
}

inline void joining_thread::join()
{
	t.join();
}

inline void joining_thread::detach()
{
	t.detach();
}

#endif // !_Joining_Thread

