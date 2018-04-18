import QtQuick 2.0
import QtGStreamer 1.0

Rectangle {
    width: 1920
    height: 1080

    VideoItem {
        id: video1

        x: 0
        y: 0
        width: 640
        height: 480
        surface: videoSurface1 //bound on the context from main()
    }
//    VideoItem {
//        id: video2

//        x: 640
//        y: 0
//        width: 640
//        height: 480
//        surface: videoSurface2 //bound on the context from main()
//    }
//    VideoItem {
//        id: video3

//        x: 1280
//        y: 0
//        width: 640
//        height: 480
//        surface: videoSurface3 //bound on the context from main()
//    }
//    VideoItem {
//        id: video4

//        x: 0
//        y: 480
//        width: 640
//        height: 480
//        surface: videoSurface4 //bound on the context from main()
//    }
    VideoItem {
        id: video5

        x: 640
        y: 480
        width: 640
        height: 480
        surface: videoSurface5 //bound on the context from main()
    }
//    VideoItem {
//        id: video6

//        x: 1280
//        y: 480
//        width: 640
//        height: 480
//        surface: videoSurface6 //bound on the context from main()
//    }
//    VideoItem {
//        id: video7

//        x: 0
//        y: 960
//        width: 640
//        height: 480
//        surface: videoSurface7 //bound on the context from main()
//    }
//    VideoItem {
//        id: video8

//        x: 640
//        y: 960
//        width: 640
//        height: 480
//        surface: videoSurface8 //bound on the context from main()
//    }
    VideoItem {
        id: video

        x: 1280
        y: 960
        width: 640
        height: 480
        surface: videoSurface9 //bound on the context from main()
    }
}
