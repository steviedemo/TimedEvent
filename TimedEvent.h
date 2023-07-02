#pragma once
#ifndef __TimedEvent_H__
#define __TimedEvent_H__
#include <stdint.h>
class TimedEvent{
	public:
		TimedEvent(uint16_t interval = 5, void (*cb)(void) = nullptr){
			this->_callback = cb;
			this->_interval = interval;
			this->_last_call = 0;
		}
		void setEventInterval(uint16_t i){
			this->_interval = i;
		}
		void attachEventCallback(void (*cb)(void)){
			if (cb){
				this->_callback = cb;
			}
		}
		uint8_t getEventInterval() { 
			return _interval; 
		}
		void process() { 
			uint16_t curr_time = millis();
			if ((curr_time - _last_call) > _interval){
				if (_callback){
					_callback();
				}
				_last_call = curr_time;
			}
		}
	private:
		void (*_callback)(void);
		uint16_t _interval, _last_call;
};

#endif
