/**
@file CustomerNode.h
@author Song Jiang
@date April 4,2018
*/



#ifndef CUSTOMERNODE_H
#define CUSTOMERNODE_H

/// Declare the struct of Customer as bankqueue node.
class Customer{
	public:
		/// Inilitialize the variables.
		Customer(){arrivalTime = 0; durationTime = 0;Next = nullptr;}
    /// Set arrivalTime
		void setArrivalTime(int const &a){ arrivalTime = a;}
		/// Get arrivalTime
		int getArrivalTime( )const {return arrivalTime;}
    /// Set durationTime
		void setDurationTime(int const &b){durationTime = b;}
		/// Get durationTime
		int getDurationTime( )const {return durationTime;}
    /// Set Next pointer
		void setNext(Customer* const &c){Next = c;}
		/// Get Next pointer
		Customer* getNext( )const {return Next;}




  private:
		int arrivalTime; ///< DEclare the variable as the time of arrival.
		int durationTime; ///< DEclare the variable as the time of arrival.
		Customer *Next; ///< DEclare the pointer that points at the next node.
};

#endif // CUSTOMERNODE_H
