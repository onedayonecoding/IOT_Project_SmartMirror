#!/bin/bash
{

export GOOGLE_APPLICATION_CREDENTIALS="/home/pi/googleassistant/smspeaker-7a7467a06fae.json"

source /home/pi/env/bin/activate

python stt.py
}

