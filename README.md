#

## Librarys

### qrencode

```sh
sudo apt-get install libqrencode-dev
sudo apt-get install qrencode
sudo apt-get install libqrencode-dev libghc-qrencode-dev libimager-qrcode-perl

# example
# -s, size
# -l, error collectin level, {L, M, Q, H}
qrencode -o qrcode.png -s 6 -l H 'http://qrcode-string'
```

# Qt Learning

Here is some Qt5 learning note and pratice examples.

## Install Qt

### Using Qt Installer

[Official releases](http://download.qt.io/official_releases/qt)

### Using brew install Qt5 on Mac OS

**(Mac is not a GOOD chioce for cross-compiler development)**
**After installed, there is no official examples!**

```Sh
Kevinteki-MacBook-Pro:qt-rtsp atomrock$ brew install qt5
==> Downloading https://homebrew.bintray.com/bottles/qt-5.10.1.high_sierra.bottle.tar.gz
######################################################################## 100.0%
==> Pouring qt-5.10.1.high_sierra.bottle.tar.gz
==> Caveats
We agreed to the Qt opensource license for you.
If this is unacceptable you should uninstall.

This formula is keg-only, which means it was not symlinked into /usr/local,
because Qt 5 has CMake issues when linked.

If you need to have this software first in your PATH run:
  echo 'export PATH="/usr/local/opt/qt/bin:$PATH"' >> ~/.bash_profile

For compilers to find this software you may need to set:
    LDFLAGS:  -L/usr/local/opt/qt/lib
    CPPFLAGS: -I/usr/local/opt/qt/include

==> Summary
🍺  /usr/local/Cellar/qt/5.10.1: 9,375 files, 295.1MB
```

- Export Toolchain Path

```sh
export PATH="$PATH:/Users/name/Qt/version/bin"
```

- Manual Compile

```sh
qmake -project # add a project.pro
qmake          # add Makefile
make
```

## Blogs of Learning and Thinking

- [QWidget、QDialog、QMainWindow的异同点](http://blog.csdn.net/liang19890820/article/details/50533262)

- [QApplication、QGuiApplication和QCoreApplication三者的区别与联系](https://my.oschina.net/lieefu/blog/816473)

- [Qt使用多线程的一些心得——1.继承QThread的多线程使用方法](http://blog.csdn.net/czyt1988/article/details/64441443)

## Qt Development on Raspberry Pi

### PiOmxTextures

- qmake -query

```sh
wen@raspberrypi:~/test/PiOmxTextures_5.7.0_pi3_5.10.0 $ qmake -query
QT_SYSROOT:
QT_INSTALL_PREFIX:/usr
QT_INSTALL_ARCHDATA:/usr/lib/arm-linux-gnueabihf/qt5
QT_INSTALL_DATA:/usr/share/qt5
QT_INSTALL_DOCS:/usr/share/qt5/doc
QT_INSTALL_HEADERS:/usr/include/arm-linux-gnueabihf/qt5
QT_INSTALL_LIBS:/usr/lib/arm-linux-gnueabihf
QT_INSTALL_LIBEXECS:/usr/lib/arm-linux-gnueabihf/qt5/libexec
QT_INSTALL_BINS:/usr/lib/arm-linux-gnueabihf/qt5/bin
QT_INSTALL_TESTS:/usr/tests
QT_INSTALL_PLUGINS:/usr/lib/arm-linux-gnueabihf/qt5/plugins
QT_INSTALL_IMPORTS:/usr/lib/arm-linux-gnueabihf/qt5/imports
QT_INSTALL_QML:/usr/lib/arm-linux-gnueabihf/qt5/qml
QT_INSTALL_TRANSLATIONS:/usr/share/qt5/translations
QT_INSTALL_CONFIGURATION:/etc/xdg
QT_INSTALL_EXAMPLES:/usr/lib/arm-linux-gnueabihf/qt5/examples
QT_INSTALL_DEMOS:/usr/lib/arm-linux-gnueabihf/qt5/examples
QT_HOST_PREFIX:/usr
QT_HOST_DATA:/usr/lib/arm-linux-gnueabihf/qt5
QT_HOST_BINS:/usr/lib/arm-linux-gnueabihf/qt5/bin
QT_HOST_LIBS:/usr/lib/arm-linux-gnueabihf
QMAKE_SPEC:linux-g++
QMAKE_XSPEC:linux-g++
QMAKE_VERSION:3.0
QT_VERSION:5.7.1

```

### Qt Debug

```sh
export QT_DEBUG_PLUGINS=1
```

### Troubleshoot

- Library issue, symbol link lib or apt-get install?!

```sh
error while loading shared libraries: libGLESv2.so: cannot open shared object file: No such file or directory
```

### Omxplayer Communication with DBus

- [source: popcornmix/omxplayer](https://github.com/popcornmix/omxplayer)

- Dbus commands reference, [omxplayer dbus control](https://github.com/popcornmix/omxplayer/blob/master/dbuscontrol.sh)

- [DBus connection to omxplayer](https://forum.qt.io/topic/88046/dbus-connection-to-omxplayer)

- [DBus connection to omxplayer won't work](https://forum.qt.io/topic/65590/dbus-connection-to-omxplayer-won-t-work)

```Qt
QDBusConnection *_dbus;
_dbus = new QDBusConnection(QDBusConnection::sessionBus());
_dbus->connectToBus(address, "org.mpris.MediaPlayer2.omxplayer");

if( !_dbus->isConnected() ) {
    qDebug() << "not connected";
}

QString dest = "org.mpris.MediaPlayer2.omxplayer";
QString path = "/org/mpris/MediaPlayer2/";
QString interface = "org.mpris.MediaPlayer2.Player";
QString name = "Action";
QDBusMessage msg = QDBusMessage::createMethodCall(dest, path, interface, name);
msg.setArguments(QList<QVariant>() << 16);
if( !_dbus->send(msg) ) {
    qWarning() << "error: " << _dbus->lastError().message();
}
```

- [Using dbuscontrol.sh to control omxplayer](https://www.raspberrypi.org/forums/viewtopic.php?t=86678)

- [Introspecting D-Bus from the command-line](http://www.kaizou.org/2014/06/dbus-command-line/)
```sh
dbus-send --system --print-reply --dest=org.freedesktop.DBus /org/freedesktop/DBus org.freedesktop.DBus.ListActivatableNames

(on RPi)
method return time=1521186203.929326 sender=org.freedesktop.DBus -> destination=:1.112 serial=3 reply_serial=2
   array [
      string "org.freedesktop.DBus"
      string "org.freedesktop.login1"
      string "org.freedesktop.ColorManager"
      string "org.freedesktop.systemd1"
      string "org.freedesktop.PolicyKit1"
      string "org.freedesktop.Avahi"
      string "org.freedesktop.hostname1"
      string "org.bluez"
      string "org.freedesktop.PackageKit"
      string "org.freedesktop.UDisks2"
      string "org.freedesktop.network1"
      string "fi.epitest.hostap.WPASupplicant"
      string "org.freedesktop.resolve1"
      string "org.freedesktop.timedate1"
      string "fi.w1.wpa_supplicant1"
      string "org.freedesktop.locale1"
   ]

dbus-send --system --print-reply --dest=org.freedesktop.DBus /org/freedesktop/DBus org.freedesktop.DBus.ListActivatableNames

(on RPi)
method return time=1521186009.651493 sender=org.freedesktop.DBus -> destination=:1.1 serial=3 reply_serial=2
   array [
      string "org.freedesktop.DBus"
      string "com.teamviewer.TeamViewer"
      string "org.gnome.GConf"
      string "org.gtk.vfs.UDisks2VolumeMonitor"
      string "org.gtk.vfs.Metadata"
      string "org.jackaudio.service"
      string "org.freedesktop.systemd1"
      string "org.xfce.Xfconf"
      string "org.gtk.vfs.AfcVolumeMonitor"
      string "org.freedesktop.PackageKit"
      string "org.gtk.vfs.Daemon"
      string "org.freedesktop.ColorHelper"
      string "org.gtk.vfs.MTPVolumeMonitor"
      string "org.gtk.GLib.PACRunner"
      string "org.gtk.vfs.GoaVolumeMonitor"
      string "org.gnome.Epiphany"
      string "ca.desrt.dconf"
      string "org.gtk.vfs.GPhoto2VolumeMonitor"
      string "com.teamviewer.TeamViewer.Desktop"
   ]
 
 (on RPi)
 dbus-send --system --print-reply --dest=org.freedesktop.DBus /org/freedesktop/DBus org.freedesktop.DBus.Introspectable.Introspect
 method return time=1521186274.362033 sender=org.freedesktop.DBus -> destination=:1.113 serial=3 reply_serial=2
 string "<!DOCTYPE node PUBLIC "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd">
<node>
  <interface name="org.freedesktop.DBus">
    <method name="Hello">
      <arg direction="out" type="s"/>
    </method>
    <method name="RequestName">
      <arg direction="in" type="s"/>
      <arg direction="in" type="u"/>
      <arg direction="out" type="u"/>
    </method>
    <method name="ReleaseName">
      <arg direction="in" type="s"/>
      <arg direction="out" type="u"/>
    </method>
    <method name="StartServiceByName">
      <arg direction="in" type="s"/>
      <arg direction="in" type="u"/>
      <arg direction="out" type="u"/>
    </method>
    <method name="UpdateActivationEnvironment">
      <arg direction="in" type="a{ss}"/>
    </method>
    <method name="NameHasOwner">
      <arg direction="in" type="s"/>
      <arg direction="out" type="b"/>
    </method>
    <method name="ListNames">
      <arg direction="out" type="as"/>
    </method>
    <method name="ListActivatableNames">
      <arg direction="out" type="as"/>
    </method>
    <method name="AddMatch">
      <arg direction="in" type="s"/>
    </method>
    <method name="RemoveMatch">
      <arg direction="in" type="s"/>
    </method>
    <method name="GetNameOwner">
      <arg direction="in" type="s"/>
      <arg direction="out" type="s"/>
    </method>
    <method name="ListQueuedOwners">
      <arg direction="in" type="s"/>
      <arg direction="out" type="as"/>
    </method>
    <method name="GetConnectionUnixUser">
      <arg direction="in" type="s"/>
      <arg direction="out" type="u"/>
    </method>
    <method name="GetConnectionUnixProcessID">
      <arg direction="in" type="s"/>
      <arg direction="out" type="u"/>
    </method>
    <method name="GetAdtAuditSessionData">
      <arg direction="in" type="s"/>
      <arg direction="out" type="ay"/>
    </method>
    <method name="GetConnectionSELinuxSecurityContext">
      <arg direction="in" type="s"/>
      <arg direction="out" type="ay"/>
    </method>
    <method name="ReloadConfig">
    </method>
    <method name="GetId">
      <arg direction="out" type="s"/>
    </method>
    <method name="GetConnectionCredentials">
      <arg direction="in" type="s"/>
      <arg direction="out" type="a{sv}"/>
    </method>
    <signal name="NameOwnerChanged">
      <arg type="s"/>
      <arg type="s"/>
      <arg type="s"/>
    </signal>
    <signal name="NameLost">
      <arg type="s"/>
    </signal>
    <signal name="NameAcquired">
      <arg type="s"/>
    </signal>
  </interface>
  <interface name="org.freedesktop.DBus.Introspectable">
    <method name="Introspect">
      <arg direction="out" type="s"/>
    </method>
  </interface>
  <interface name="org.freedesktop.DBus.Monitoring">
    <method name="BecomeMonitor">
      <arg direction="in" type="as"/>
      <arg direction="in" type="u"/>
    </method>
  </interface>
  <interface name="org.freedesktop.DBus.Debug.Stats">
    <method name="GetStats">
      <arg direction="out" type="a{sv}"/>
    </method>
    <method name="GetConnectionStats">
      <arg direction="in" type="s"/>
      <arg direction="out" type="a{sv}"/>
    </method>
    <method name="GetAllMatchRules">
      <arg direction="out" type="a{sas}"/>
    </method>
  </interface>
</node>
"
```
