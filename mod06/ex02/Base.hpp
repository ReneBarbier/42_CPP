#pragma once

#include <iostream>
#include <exception>
#include <random>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

