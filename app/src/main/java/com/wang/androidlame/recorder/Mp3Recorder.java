package com.wang.androidlame.recorder;

public final class Mp3Recorder {

    private static final int SAMPLE_RATE = 48_000; // 44100
    private static final int CHANNEL_COUNT = 2; // 双声道
    private static final int BITRATE = 148000; // 比特率




    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    /**
     *
     * @param inSampleRate
     * @param outChannel
     * @param outSampleRate
     * @param outBitrate
     * @param quality quality=0..9.  0=best (very slow).  9=worst.
     *      recommended:  3     near-best quality, not too slow
     *                    5     good quality, fast
     *                    7     ok quality, really fast
     */
    public native void initLame(int inSampleRate, int outChannel, int outSampleRate, int outBitrate, int quality);
}
