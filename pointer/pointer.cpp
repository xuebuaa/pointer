// pointer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

namespace test_shared_ptr
{
	struct Destination
	{

	};
	struct Connection
	{

	};

	Connection connect(Destination*);
}

namespace unique_pointer
{
	void test()
	{
		std::unique_ptr<double> p1;
		unique_ptr<string> p2 = make_unique<string>("hello");
		//unique_ptr<string> p3 = p2;
		unique_ptr<string> p3;
		p3.reset(p2.release());
		p3.reset();
	}
	void test2()
	{
		unique_ptr<int[]> u1(new int[10]);
		u1.release();
	}

}

//namespace weak_pointer
//{
//	void test()
//	{
//		auto p = make_shared<int>(42);
//		weak_ptr<int> p2 = p;
//		cout << p2.expired();
//	}
//
//	class StrBlob;
//	class StrBlobPtr
//	{
//	public:
//		
//		StrBlobPtr() :curr(0) {}
//		StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
//		string& deref()const;
//		StrBlobPtr& incr();
//	private:
//		size_t curr;
//		shared_ptr<vector<string>> check(size_t, const string&)const;
//		weak_ptr<vector<string>> wptr;
//	};
//
//	shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
//	{
//		auto ret = wptr.lock();
//		if (!ret)
//			throw runtime_error("unbound StrBlobPtr");
//		if (i >= ret->size())
//			throw out_of_range(msg);
//		return ret;
//	}
//
//	string& StrBlobPtr::deref() const {
//		auto p = check(curr, "dereference past end");
//		return (*p)[curr];
//	}
//
//	StrBlobPtr& StrBlobPtr::incr()
//	{
//		check(curr, "increment past end of StrBlobPtr");
//		++curr;
//		return *this;
//	}
//
//	class StrBlob
//	{
//	public:
//		using size_type = std::vector<string>::size_type;
//		friend class StrBlobPtr;
//		StrBlobPtr begin() { return StrBlobPtr(*this); }
//		StrBlobPtr end() {
//			auto ret = StrBlobPtr(*this, data->size());
//			return ret;
//		}
//		StrBlob();
//		StrBlob(initializer_list<string> il);
//		size_type size() const { return data->size(); }
//		bool empty() const { return data->empty(); }
//
//		void push_back(const string& t) { data->push_back(t); }
//		void pop_back();
//		const string& front()const;
//		const string& back()const;
//
//		shared_ptr<vector<string>> data;
//	private:
//		void check(size_type i, const string& msg)const;
//		~StrBlob() {};
//
//	};
//	StrBlob::StrBlob() :data(make_shared<vector<string>>())
//	{
//
//	}
//	StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il))
//	{
//	}
//
//	const std::string& StrBlob::front() const
//	{
//		check(0, "front on empty StrBlob");
//		return data->front();
//	}
//	const std::string& StrBlob::back() const
//	{
//		check(0, "back on empty StrBlob");
//		return data->back();
//	}
//	void StrBlob::check(size_type i, const string& msg)const
//	{
//		if (i >= data->size())
//			throw out_of_range(msg);
//	}
//	void StrBlob::pop_back()
//	{
//		check(0, "pop_back on empty StrBlob");
//		data->pop_back();
//	}
//}

namespace alloc
{
	void test()
	{
		const int n = 10;
		allocator<string> al;
		auto const p = al.allocate(n);
		auto q = p;
		al.construct(q++);
		al.construct(q++, 10, 'a');
		al.construct(q++, "hi");
		cout << *p << endl;
		cout << *q << endl;

	}
}
int main()
{
	alloc::test();
}


