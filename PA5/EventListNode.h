/**
@file EventListNode.h
@author Song Jiang
@date April 4,2018
*/



#ifndef EVENTLISTNODE_H
#define EVENTLISTNODE_H

/// Declare the struct of Customer as eventlistPQueue node.
class Event{

  public:
    /// Inilitialize the variables.
    Event(){eventTime = 0; eventTimeLenth = 0; eventnext = nullptr;}
    /// Set eventTime
    void setEventTime(const int &a){eventTime = a;}
    /// Get eventTime
    int getEventTime( ) const{return eventTime;}
    /// Set eventTimeLenth
    void setEventTimeLenth(int const &b){eventTimeLenth = b;}
    /// Get eventTimeLenth
    int getEventTimeLenth( ) const{return eventTimeLenth;}
    /// Set eventType
    void setEventType(int const &c){eventType = c;}
    /// Get eventType
    int getEventType( ) const{return eventType;}
    /// Set eventnext
    void setEventnext( Event* const  &d){eventnext = d;}
    /// Get eventnext
    Event* getEventnext( ) const{return eventnext;}

  private:
    int eventTime; ///< Declare the time of event happening(priority).
    int eventTimeLenth;///< Declare the time length of event.
    int eventType;///< Declare the type of event: -1 means arrival, others means departure.
    Event *eventnext;///< Dclare the poniter.

};

#endif // EVENTLISTNODE_H
