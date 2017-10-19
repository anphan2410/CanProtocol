#include <QCoreApplication>
#include "src/canprotocol.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CanProtocol aSample;
    aSample = QCanBusFrame(0x72,QByteArray::fromHex(QByteArray("4BAFED2200000001")));
    CanProtocol aTest;
    aTest.setSdcsId(7).setChId(2).setRFID(QByteArray::fromHex(QByteArray("4BAFED22"))).setValveOn();

    qDebug().noquote() << "===CAN PROTOCOL TESTER=========================================";

    qDebug().noquote() << "MSG      : " << aTest.getMsgStr() << "\n     vs  : " << aSample.getMsgStr();
    qDebug().noquote() << "MSG MEAN : " << aTest.getMsgMean() << " vs " << aSample.getMsgMean();
    qDebug().noquote() << "FrameId  : " << QString::number(aTest.frameId(),16)
                       << " vs " << QString::number(aSample.frameId(),16);
    qDebug().noquote() << "PayloadId: " << aTest.payload().toHex() << " vs " << aSample.payload().toHex();
    qDebug().noquote() << "   SdcsID: " << aTest.getSdcsId() << " vs " << aSample.getSdcsId();
    qDebug().noquote() << "     ChID: " << aTest.getChId() << " vs " << aSample.getChId();
    qDebug().noquote() << "     RFID: " << aTest.getRFID().toHex() << " vs " << aSample.getRFID().toHex();
    qDebug().noquote() << "    Valve: " << aTest.getValveControl() << " vs " << aSample.getValveControl();
    qDebug().noquote() << "     SetB: " << aTest.getValveControlSetBit() << " vs " << aSample.getValveControlSetBit();
    qDebug().noquote() << "   ResetB: " << aTest.getValveControlResetBit() << " vs " << aSample.getValveControlResetBit();


    qDebug().noquote() << "================================================================";

    return a.exec();
}
