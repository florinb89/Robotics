#ifndef ROBOTFRAMEWORK_PIN_H
#define ROBOTFRAMEWORK_PIN_H

namespace RobotFramework
{
	template <class T>
	class PinReader 
	{
		public:
			PinReader(T (*readFunction) (unsigned char port)){
				this->readFunction = readFunction;
			};
			~PinReader(){};

		T Read(unsigned char port){
			return readFunction(port);
		}

	private:
		T (*readFunction)(unsigned char port);
	};

	template <class T>
	class PinWriter
	{
	public:
		PinWriter(void (*writeFunction)(unsigned char port, T data)){
			this->writeFunction = writeFunction;
		};
		~PinWriter(){};

		void Write(unsigned char port, T data)
		{
			this->writeFunction(port, data);
		};

	private:
		void (*writeFunction)(unsigned char port, T data);
	};

}

#endif
