#pragma once

#include <queue>
#include <vector>
#include <iostream>
#define DIGITS "0123456789"

class	Monkey	{
	protected:
		std::queue<int>	items;
		int		x;
		int		test;
		int		idx1;
		int		idx2;
		Monkey		*m1;
		Monkey		*m2;
		int		inspected;
	public:
		Monkey(): inspected(0){}
		~Monkey(){}
		void	setX(int y)	{
			x = y;
		}
		void	setTest(int t)	{
			test = t;
		}
		void	setIdx1(int i)	{
			idx1 = i;
		}
		void	setIdx2(int i)	{
			idx2 = i;
		}
		void	setMates(Monkey *p1, Monkey *p2)	{
			m1 = p1;
			m2 = p2;
		}
		void	setMates(std::vector<Monkey *> &m)	{
			m1 = m[idx1];
			m2 = m[idx2];
		}
		void	setItems(std::vector<int> v)	{
			for (int i = 0; i < v.size(); i++)	{
				items.push(v[i]);
			}
		}
		void	catchItem(int item)	{
			items.push(item);
		}
		void	throwItem(int item, Monkey *m)	{
			m->catchItem(item);
		}
		int virtual	inspect(int &i) = 0;
		void	inspectItems()	{
			while (!items.empty())	{
				int i = items.front();
				items.pop();
				if (inspect(i))
					throwItem(i, m2);
				else
					throwItem(i, m1);
				inspected++;
			}
		}
		int getInspected()	{
			return (inspected);
		}
		
};	

class	mSum : public Monkey	{
	public:
		mSum(){}
		virtual ~mSum(){}
		int	inspect(int &i)	{
			i += x;
			i /= 3;
			return i % test;
		}
};
class	mPow : public Monkey	{
	public:
		mPow(){}
		virtual ~mPow(){}
		int	inspect(int &i)	{
			i *= i;
			i /= 3;
			return i % test;
		}
};
class	mMlt : public Monkey	{
	public:
		mMlt(){}
		virtual ~mMlt(){}
		int	inspect(int &i)	{
			i *= x;
			i /= 3;
			return i % test;
		}
};
