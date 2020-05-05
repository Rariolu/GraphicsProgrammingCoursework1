#ifndef _AUDIODEVICE_H
#define _AUDIODEVICE_H

#include <al.h>
#include <alc.h>
#include "Camera.h"
#include "Logger.h"

namespace GraphicsProgramming
{

	//Establishes a connection to the primary audio device
	//and allows audio to be played using it.
	class AudioDevice
	{
		//Represents a particular instantiation of an
		//an audio file (uniquely identified by the "bufferID"
		//(the ID of the audio itself) and the "sourceID" (the
		//ID of the particular in-world source).
		struct SoundData
		{
			int bufferID;
			int sourceID;
			const char* filename;
			SoundData(unsigned int sI, unsigned int bI, const char* n)
			{
				sourceID = sI;
				bufferID = bI;
				filename = n;
			}
		};
	public:
		//Return the current instance of "AudioDevice"
		//(creating one if it's null).
		static AudioDevice* Instance();
		~AudioDevice();

		//Load the audio from a given file into memory
		//and return a unique identifier to use this audio
		//when needed.
		unsigned int LoadSound(const char* filename);

		//Play the sound indicated by the given source ID.
		void PlaySound(unsigned int id);

		//Play the sound indicaed by the given source ID, at the given world coordinates.
		void PlaySound(unsigned int id, Vec3 pos);

		//Set the "listener" according to the
		//given camera's position and orientation.
		void SetListener(Camera* camera);

		//Stop playing the audio source
		//of the given ID.
		void StopSound(unsigned int id);
	private:
		AudioDevice();

		//Convert a requested portion of the char pointer
		//into an integer.
		int ConvertToInt(char* buffer, int length);

		//Delete the given audio source.
		void DeleteSound(unsigned int id);

		//Load a wave file from the given file path, setting the other
		//parameter values accordingly.
		char* LoadWave(const char* filename, int& channel, int& samplerate, int& bps, int& size);

		//Set the value of "isBigEndian" depending on
		//whether this system is using big endian or little endian.
		void SetIsBigEndian();

		//The current instance of "AudioDevice".
		static AudioDevice* instance;

		//A pointer to the current openAL context.
		ALCcontext* context;

		//A pointer to the openAL audio device.
		ALCdevice* device;

		//A collection of the metadata of loaded audio.
		vector<SoundData> datas;

		//A boolean determining whether or not this system
		//is using big endian or little endian.
		bool isBigEndian;
	};

}

#endif