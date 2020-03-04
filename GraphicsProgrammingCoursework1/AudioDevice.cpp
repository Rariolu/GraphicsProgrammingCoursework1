#include "AudioDevice.h"

AudioDevice* AudioDevice::instance = nullptr;

AudioDevice::AudioDevice()
{
	device = alcOpenDevice(nullptr);
	if (!device)
	{
		Log("Couldn't open openAL audio device.");
	}
	context = alcCreateContext(device, nullptr);
	if (!context)
	{
		Log("Couldn't initialise openAL context.");
	}
	alcMakeContextCurrent(context);
	SetIsBigEndian();
}

AudioDevice::~AudioDevice()
{
	for (unsigned int i = 0; i < datas.size(); i++)
	{
		alDeleteSources(1, (unsigned int*)& datas[i].sourceID);
		if (datas[i].bufferID != -1)
		{
			DeleteSound(datas[i].bufferID);
		}
	}
	alcDestroyContext(context);
	alcCloseDevice(device);
}

AudioDevice* AudioDevice::Instance()
{
	if (!instance)
	{
		return instance = new AudioDevice();
	}
	return instance;
}

unsigned int AudioDevice::LoadSound(const char* filename)
{
	bool found = false;
	unsigned int sourceID;
	unsigned int bufferID;

	//Loops through the stored audio metadata to find
	//a match for the requested file (in case it is accidentally
	//attemptedly loaded twice).
	for (unsigned int i = 0; i < datas.size(); i++)
	{
		//If the current metadata uses the same file
		//and has a buffer ID of not -1 (i.e. isn't 
		//a duplicate entry for that file).
		if (datas[i].filename == filename && datas[i].bufferID != -1)
		{
			//Set the current "bufferID" to
			//the one of the loaded file.
			bufferID = datas[i].bufferID;

			//Set "found" to true to indicate
			//that the stored information
			//was found.
			found = true;

			//Exit the loop to avoid unnecessarily
			//searching through the rest of the entries.
			break;
		}
	}

	//If the file wasn't found (i.e. wasn't previously loaded).
	if (!found)
	{
		char* soundData = nullptr;
		int channel, sampleRate, bps, size;

		//Load the audio data from the given file path, setting the values
		//of "channel", "sampleRate", "bps", and "size" appropriately.
		soundData = LoadWave(filename, channel, sampleRate, bps, size);

		unsigned int format;

		//Create a buffer ID to identify this particular audio data.
		alGenBuffers(1, &bufferID);

		if (channel == 1)
		{
			if (bps == 8)
			{
				format = AL_FORMAT_MONO8;
			}
			else
			{
				format = AL_FORMAT_MONO16;
			}
		}
		else
		{
			if (bps == 8)
			{
				format = AL_FORMAT_STEREO8;
			}
			else
			{
				format = AL_FORMAT_STEREO16;
			}
		}

		alBufferData(bufferID, format, soundData, size, sampleRate);
	}
	alGenSources(1, &sourceID);
	alSourcei(sourceID, AL_BUFFER, bufferID);
	alSourcef(sourceID, AL_REFERENCE_DISTANCE, 1.0f);
	SoundData sd = SoundData(sourceID, !found ? bufferID : -1, filename);
	datas.push_back(sd);
	return sourceID;
}

void AudioDevice::PlaySound(unsigned int id)
{
	alSourcePlay(id);
}

void AudioDevice::PlaySound(unsigned int id, Vec3 pos)
{
	alSource3f(id, AL_POSITION, pos.x, pos.y, pos.z);
	PlaySound(id);
}

void AudioDevice::SetListener(Camera* camera)
{
	Vec3 pos = *camera->GetPosition();
	Vec3 dir = *camera->GetForward();
	alListener3f(AL_POSITION, pos.x, pos.y, -pos.z);
	float orinetation[6] = { dir.x, dir.y, dir.z,0,1,0 };
	alListenerfv(AL_ORIENTATION, orinetation);
}

void AudioDevice::StopSound(unsigned int id)
{
	alSourceStop(id);
}

int AudioDevice::ConvertToInt(char* buffer, int length)
{
	int a = 0;
	if (isBigEndian)
	{
		for (int i = 0; i < length; i++)
		{
			((char*)& a)[3 - i] = buffer[i];
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			((char*)& a)[i] = buffer[i];
		}
	}
	return a;
}

void AudioDevice::DeleteSound(unsigned int id)
{
	alDeleteBuffers(1, (unsigned int*)& id);
}

void AudioDevice::SetIsBigEndian()
{
	int a = 1;
	isBigEndian = !((char*)& a)[0];
}

char* AudioDevice::LoadWave(const char* filename, int& channel, int& samplerate, int& bps, int& size)
{
	char buffer[4];
	InputFileStream in(filename, std::ios::binary);
	in.read(buffer, 4);
	in.read(buffer, 4);
	in.read(buffer, 4); //WAV
	in.read(buffer, 4);	//fmt
	in.read(buffer, 4); //16 bit
	in.read(buffer, 2); //1
	in.read(buffer, 2);
	channel = ConvertToInt(buffer, 2);
	in.read(buffer, 4);
	samplerate = ConvertToInt(buffer, 4);
	in.read(buffer, 4);
	in.read(buffer, 2);
	in.read(buffer, 2);
	bps = ConvertToInt(buffer, 2);
	in.read(buffer, 4);
	in.read(buffer, 4);
	size = ConvertToInt(buffer, 4);

	char* soundData = new char[size];
	in.read(soundData, size);
	return soundData;
}