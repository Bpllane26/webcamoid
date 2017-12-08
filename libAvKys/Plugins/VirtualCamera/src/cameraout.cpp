/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2017  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#include "cameraout.h"

#define PASSWORD_TIMEOUT 2500

CameraOut::CameraOut(QObject *parent):
    QObject(parent),
    m_passwordTimeout(PASSWORD_TIMEOUT)
{
}

CameraOut::~CameraOut()
{
}

QString CameraOut::driverPath() const
{
    return this->m_driverPath;
}

QStringList CameraOut::webcams() const
{
    return QStringList();
}

QString CameraOut::device() const
{
    return this->m_device;
}

int CameraOut::streamIndex() const
{
    return -1;
}

AkCaps CameraOut::caps() const
{
    return this->m_caps;
}

QString CameraOut::description(const QString &webcam) const
{
    Q_UNUSED(webcam)

    return QString();
}

void CameraOut::writeFrame(const AkPacket &frame)
{
    Q_UNUSED(frame)
}

int CameraOut::maxCameras() const
{
    return 0;
}

bool CameraOut::needRoot() const
{
    return false;
}

int CameraOut::passwordTimeout() const
{
    return this->m_passwordTimeout;
}

QString CameraOut::rootMethod() const
{
    return this->m_rootMethod;
}

QString CameraOut::createWebcam(const QString &description,
                                const QString &password)
{
    Q_UNUSED(description)
    Q_UNUSED(password)

    return QString();
}

bool CameraOut::changeDescription(const QString &webcam,
                                  const QString &description,
                                  const QString &password)
{
    Q_UNUSED(webcam)
    Q_UNUSED(description)
    Q_UNUSED(password)

    return false;
}

bool CameraOut::removeWebcam(const QString &webcam,
                             const QString &password)
{
    Q_UNUSED(webcam)
    Q_UNUSED(password)

    return false;
}

bool CameraOut::removeAllWebcams(const QString &password)
{
    Q_UNUSED(password)

    return true;
}

bool CameraOut::init(int streamIndex)
{
    Q_UNUSED(streamIndex)

    return false;
}

void CameraOut::uninit()
{
}

void CameraOut::setDriverPath(const QString &driverPath)
{
    if (this->m_driverPath == driverPath)
        return;

    this->m_driverPath = driverPath;
    emit this->driverPathChanged(this->m_driverPath);
}

void CameraOut::setDevice(const QString &device)
{
    if (this->m_device == device)
        return;

    this->m_device = device;
    emit this->deviceChanged(this->m_device);
}

void CameraOut::setCaps(const AkCaps &caps)
{
    if (this->m_caps == caps)
        return;

    this->m_caps = caps;
    emit this->capsChanged(this->m_caps);
}

void CameraOut::setPasswordTimeout(int passwordTimeout)
{
    if (this->m_passwordTimeout == passwordTimeout)
        return;

    this->m_passwordTimeout = passwordTimeout;
    emit this->passwordTimeoutChanged(this->m_passwordTimeout);
}

void CameraOut::setRootMethod(const QString &rootMethod)
{
    if (this->m_rootMethod == rootMethod)
        return;

    this->m_rootMethod = rootMethod;
    emit this->rootMethodChanged(this->m_rootMethod);
}

void CameraOut::resetDriverPath()
{
    this->setDriverPath("");
}

void CameraOut::resetDevice()
{
    this->setDevice("");
}

void CameraOut::resetCaps()
{
    this->setCaps(AkCaps());
}

void CameraOut::resetPasswordTimeout()
{
    this->setPasswordTimeout(PASSWORD_TIMEOUT);
}

void CameraOut::resetRootMethod()
{
    this->setRootMethod("");
}

#include "moc_cameraout.cpp"
