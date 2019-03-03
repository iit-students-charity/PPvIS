#include <string>

#pragma once
#ifndef TRANSPORT_H
#define TRANSPORT_H

namespace transp
{
	class Transport
	{
	protected:
		unsigned int maxSpeed;
		unsigned int maxLoad;
		unsigned int weight;
	public:
		Transport();

		void set_maxSpeed(int maxSpeed);

		unsigned int get_maxSpeed();

		void set_maxLoad(int maxLoad);

		unsigned int get_maxLoad();

		void set_weight(int weight);

		unsigned int get_weight();

		virtual void hit_the_road();
	};


	class Air_Transport : public Transport
	{
	protected:
		unsigned int maxHeight;
		bool haveEngine;
	public:
		Air_Transport();

		void set_maxHeight(int maxHeight);

		unsigned int get_maxHeight();

		void set_haveEngine(int maxLoad);

		bool get_haveEngine();
	};


	class Ground_Transport : public Transport
	{
	protected:
		unsigned int wheelsCount;
		std::string engineType;
	public:
		Ground_Transport();

		void set_wheelsCount(unsigned int wheelsCount);

		int get_wheelsCount();

		void set_engineType(std::string engineType);

		std::string get_engineType();
	};


	class Water_Transport : public Transport
	{
	protected:
		unsigned int crewCount;
		bool isWomanOnBoard;
	public:
		Water_Transport();

		void set_crewCount(unsigned int crewCount);

		unsigned int get_crewCount();

		void set_isWomanOnBoard(bool isWomanOnBoard);

		bool get_isWomanOnBoard();
	};


	class Planes : public Air_Transport
	{
	private:
		unsigned int wingsCount;
		bool isIFR;
	public:
		Planes();

		void set_wingCount(unsigned int wingsCount);

		unsigned int get_wingsCount();

		void set_isIFR(bool isIFR);

		bool get_isIFR();

		void hit_the_road() override;
	};


	class Helicopters : public Air_Transport
	{
	private:
		unsigned int screwCount;
		std::string chassisType;
	public:
		Helicopters();

		void set_wingCount(unsigned int screwCount);

		unsigned int get_screwCount();

		void set_chassisType(std::string chassisType);

		std::string get_chassisType();

		void hit_the_road() override;
	};


	class Trains : public Ground_Transport
	{
	private:
		unsigned int trackGauge;
	public:
		Trains();

		void set_trackGauge(unsigned int trackGauge);

		unsigned int get_trackGauge();

		void hit_the_road() override;
	};


	class Cars : public virtual Ground_Transport
	{
	protected:
		unsigned int mantaincePricePerYear;
		bool isAutopilot;
	public:
		Cars();

		void set_mantaincePricePerYear(unsigned int mantaincePricePerYear);

		unsigned int get_mantaincePricePerYear();

		void set_isAutopilot(bool isAutopilot);

		bool get_isAutopilot();

		void hit_the_road() override;
	};


	class Submarines : public Water_Transport
	{
	private:
		unsigned int maxDepth;
		bool isYellow;
	public:
		Submarines();

		void set_maxDepth(unsigned int maxDepth);

		unsigned int get_maxDepth();

		void set_isYellow(bool isYellow);

		bool get_isYellow();

		void hit_the_road() override;
	};


	class Ships : public virtual Water_Transport
	{
	protected:
		unsigned int displacement;
		std::string boardNumber;
	public:
		Ships();

		void set_displacement(unsigned int displacement);

		unsigned int get_displacement();

		void set_boardNumber(std::string boardNumber);

		std::string get_boardNumber();

		void hit_the_road() override;
	};


	class Amphibians : public virtual Water_Transport,
		public virtual Ground_Transport
	{};
}

#endif
