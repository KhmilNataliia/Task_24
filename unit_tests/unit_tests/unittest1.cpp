#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "state.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{	
	TEST_CASE("created")
	{
		Grant *gr = new Grant("John");
		string stat = gr->get_status();
		REQUIRE(stat == "status: created;");
	};
	TEST_CASE("consider")
	{
		Grant *gr = new Grant("John");
		gr->change_status(2);
		string stat = gr->get_status();
		REQUIRE(stat == "status: in consideration;");
	};
	TEST_CASE("postpon")
	{
		Grant *gr = new Grant("John");
		gr->change_status(3);
		string stat = gr->get_status();
		REQUIRE(stat == "status: postponed;");
	};
	TEST_CASE("reject")
	{
		Grant *gr = new Grant("John");
		gr->change_status(4);
		string stat = gr->get_status();
		REQUIRE(stat == "status: rejected;");
	};
	TEST_CASE("affirm")
	{
		Grant *gr = new Grant("John");
		gr->change_status(5);
		string stat = gr->get_status();
		REQUIRE(stat == "status: affirmed;");
	};
	TEST_CASE("revoke")
	{
		Grant *gr = new Grant("John");
		gr->change_status(6);
		string stat = gr->get_status();
		REQUIRE(stat == "status: revoked;");
	};
	TEST_CASE("cr")
	{
		Grant *gr = new Grant("John");
		gr->change_status(5);
		gr->change_status(1);
		string stat = gr->get_status();
		REQUIRE(stat == "status: created;");
	};
	TEST_CASE("name")
	{
		Grant *gr = new Grant("John");
		string n = gr->get_name();
		REQUIRE(n=="John");
	};
}