/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Canvas2D.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionRevert;
    QAction *actionCopy3Dto2D;
    QAction *actionClear;
    QAction *actionUseOrbitingCamera;
    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QTabWidget *tabWidget;
    QWidget *tab2D;
    QGridLayout *gridLayout_11;
    QScrollArea *scrollArea;
    Canvas2D *canvas2D;
    QWidget *tab3D;
    QGridLayout *gridLayout_12;
    QWidget *canvas3D;
    QDockWidget *rayDock;
    QWidget *rayDockContents;
    QVBoxLayout *verticalLayout_4;
    QWidget *rayAllOrNone;
    QHBoxLayout *horizontalLayout;
    QPushButton *rayAllButton;
    QPushButton *rayNoneButton;
    QGroupBox *rayFeatures;
    QVBoxLayout *verticalLayout_11;
    QCheckBox *raySuperSamping;
    QWidget *raySuperSamples;
    QGridLayout *gridLayout_7;
    QLabel *raySuperSamplesLabel;
    QLineEdit *raySuperSamplesTextbox;
    QCheckBox *rayAntiAliasing;
    QCheckBox *rayShadows;
    QCheckBox *rayTextureMapping;
    QCheckBox *rayReflection;
    QCheckBox *rayRefraction;
    QCheckBox *rayMultiThreading;
    QCheckBox *rayUseKDTree;
    QGroupBox *rayLighting;
    QVBoxLayout *verticalLayout_9;
    QCheckBox *rayPointLights;
    QCheckBox *rayDirectionalLights;
    QCheckBox *raySpotLights;
    QPushButton *rayRenderButton;
    QPushButton *rayStopRenderingButton;
    QWidget *rayDockEmptySpace;
    QDockWidget *camtransDock;
    QWidget *camtransDockContents;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *cameraOrbitCheckbox;
    QGroupBox *cameraPosition;
    QGridLayout *gridLayout;
    QLabel *cameraPositionLabelX;
    QLabel *cameraPositionLabelY;
    QLabel *cameraPositionLabelZ;
    QDial *transX;
    QDial *transY;
    QDial *transZ;
    QGroupBox *cameraRotation;
    QVBoxLayout *verticalLayout_13;
    QWidget *cameraRotation_2;
    QGridLayout *gridLayout_15;
    QDial *rotU;
    QDial *rotV;
    QDial *rotW;
    QLabel *cameraRotationLabelYaw;
    QLabel *cameraRotationLabelPitch;
    QLabel *cameraRotationLabelRoll;
    QPushButton *resetUpVector;
    QGroupBox *cameraResetAxis;
    QGridLayout *gridLayout_14;
    QPushButton *xAxisButton;
    QPushButton *yAxisButton;
    QPushButton *zAxisButton;
    QPushButton *axonometricButton;
    QWidget *cameraFrustum;
    QGridLayout *gridLayout_5;
    QLabel *cameraFovLabel;
    QLineEdit *cameraFovTextbox;
    QSlider *cameraFovSlider;
    QLabel *cameraNearLabel;
    QLineEdit *cameraNearTextbox;
    QLabel *cameraFarLabel;
    QLineEdit *cameraFarTextbox;
    QSlider *cameraNearSlider;
    QSlider *cameraFarSlider;
    QPushButton *resetSliders;
    QLabel *cameraAspectRatio;
    QLabel *label;
    QWidget *cameraDockEmptySpace;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuToolbars;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 3112);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks|QMainWindow::VerticalTabs);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionRevert = new QAction(MainWindow);
        actionRevert->setObjectName(QString::fromUtf8("actionRevert"));
        actionRevert->setEnabled(true);
        actionCopy3Dto2D = new QAction(MainWindow);
        actionCopy3Dto2D->setObjectName(QString::fromUtf8("actionCopy3Dto2D"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionUseOrbitingCamera = new QAction(MainWindow);
        actionUseOrbitingCamera->setObjectName(QString::fromUtf8("actionUseOrbitingCamera"));
        actionUseOrbitingCamera->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_10 = new QGridLayout(centralWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tab2D = new QWidget();
        tab2D->setObjectName(QString::fromUtf8("tab2D"));
        gridLayout_11 = new QGridLayout(tab2D);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab2D);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        canvas2D = new Canvas2D();
        canvas2D->setObjectName(QString::fromUtf8("canvas2D"));
        canvas2D->setGeometry(QRect(0, 0, 339, 3059));
        scrollArea->setWidget(canvas2D);

        gridLayout_11->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab2D, QString());
        tab3D = new QWidget();
        tab3D->setObjectName(QString::fromUtf8("tab3D"));
        gridLayout_12 = new QGridLayout(tab3D);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        canvas3D = new QWidget(tab3D);
        canvas3D->setObjectName(QString::fromUtf8("canvas3D"));

        gridLayout_12->addWidget(canvas3D, 0, 0, 1, 1);

        tabWidget->addTab(tab3D, QString());

        gridLayout_10->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        rayDock = new QDockWidget(MainWindow);
        rayDock->setObjectName(QString::fromUtf8("rayDock"));
        rayDockContents = new QWidget();
        rayDockContents->setObjectName(QString::fromUtf8("rayDockContents"));
        verticalLayout_4 = new QVBoxLayout(rayDockContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        rayAllOrNone = new QWidget(rayDockContents);
        rayAllOrNone->setObjectName(QString::fromUtf8("rayAllOrNone"));
        horizontalLayout = new QHBoxLayout(rayAllOrNone);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rayAllButton = new QPushButton(rayAllOrNone);
        rayAllButton->setObjectName(QString::fromUtf8("rayAllButton"));

        horizontalLayout->addWidget(rayAllButton);

        rayNoneButton = new QPushButton(rayAllOrNone);
        rayNoneButton->setObjectName(QString::fromUtf8("rayNoneButton"));

        horizontalLayout->addWidget(rayNoneButton);


        verticalLayout_4->addWidget(rayAllOrNone);

        rayFeatures = new QGroupBox(rayDockContents);
        rayFeatures->setObjectName(QString::fromUtf8("rayFeatures"));
        verticalLayout_11 = new QVBoxLayout(rayFeatures);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 5, -1, 5);
        raySuperSamping = new QCheckBox(rayFeatures);
        raySuperSamping->setObjectName(QString::fromUtf8("raySuperSamping"));

        verticalLayout_11->addWidget(raySuperSamping);

        raySuperSamples = new QWidget(rayFeatures);
        raySuperSamples->setObjectName(QString::fromUtf8("raySuperSamples"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(raySuperSamples->sizePolicy().hasHeightForWidth());
        raySuperSamples->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(raySuperSamples);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(6);
        gridLayout_7->setContentsMargins(-1, 0, -1, 0);
        raySuperSamplesLabel = new QLabel(raySuperSamples);
        raySuperSamplesLabel->setObjectName(QString::fromUtf8("raySuperSamplesLabel"));
        sizePolicy.setHeightForWidth(raySuperSamplesLabel->sizePolicy().hasHeightForWidth());
        raySuperSamplesLabel->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(raySuperSamplesLabel, 1, 1, 1, 1);

        raySuperSamplesTextbox = new QLineEdit(raySuperSamples);
        raySuperSamplesTextbox->setObjectName(QString::fromUtf8("raySuperSamplesTextbox"));
        raySuperSamplesTextbox->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(raySuperSamplesTextbox->sizePolicy().hasHeightForWidth());
        raySuperSamplesTextbox->setSizePolicy(sizePolicy1);
        raySuperSamplesTextbox->setMinimumSize(QSize(40, 0));
        raySuperSamplesTextbox->setMaximumSize(QSize(40, 16777215));

        gridLayout_7->addWidget(raySuperSamplesTextbox, 1, 0, 1, 1);


        verticalLayout_11->addWidget(raySuperSamples);

        rayAntiAliasing = new QCheckBox(rayFeatures);
        rayAntiAliasing->setObjectName(QString::fromUtf8("rayAntiAliasing"));

        verticalLayout_11->addWidget(rayAntiAliasing);

        rayShadows = new QCheckBox(rayFeatures);
        rayShadows->setObjectName(QString::fromUtf8("rayShadows"));

        verticalLayout_11->addWidget(rayShadows);

        rayTextureMapping = new QCheckBox(rayFeatures);
        rayTextureMapping->setObjectName(QString::fromUtf8("rayTextureMapping"));

        verticalLayout_11->addWidget(rayTextureMapping);

        rayReflection = new QCheckBox(rayFeatures);
        rayReflection->setObjectName(QString::fromUtf8("rayReflection"));

        verticalLayout_11->addWidget(rayReflection);

        rayRefraction = new QCheckBox(rayFeatures);
        rayRefraction->setObjectName(QString::fromUtf8("rayRefraction"));

        verticalLayout_11->addWidget(rayRefraction);

        rayMultiThreading = new QCheckBox(rayFeatures);
        rayMultiThreading->setObjectName(QString::fromUtf8("rayMultiThreading"));

        verticalLayout_11->addWidget(rayMultiThreading);

        rayUseKDTree = new QCheckBox(rayFeatures);
        rayUseKDTree->setObjectName(QString::fromUtf8("rayUseKDTree"));

        verticalLayout_11->addWidget(rayUseKDTree);


        verticalLayout_4->addWidget(rayFeatures);

        rayLighting = new QGroupBox(rayDockContents);
        rayLighting->setObjectName(QString::fromUtf8("rayLighting"));
        verticalLayout_9 = new QVBoxLayout(rayLighting);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, 5, -1, 5);
        rayPointLights = new QCheckBox(rayLighting);
        rayPointLights->setObjectName(QString::fromUtf8("rayPointLights"));

        verticalLayout_9->addWidget(rayPointLights);

        rayDirectionalLights = new QCheckBox(rayLighting);
        rayDirectionalLights->setObjectName(QString::fromUtf8("rayDirectionalLights"));

        verticalLayout_9->addWidget(rayDirectionalLights);

        raySpotLights = new QCheckBox(rayLighting);
        raySpotLights->setObjectName(QString::fromUtf8("raySpotLights"));

        verticalLayout_9->addWidget(raySpotLights);


        verticalLayout_4->addWidget(rayLighting);

        rayRenderButton = new QPushButton(rayDockContents);
        rayRenderButton->setObjectName(QString::fromUtf8("rayRenderButton"));

        verticalLayout_4->addWidget(rayRenderButton);

        rayStopRenderingButton = new QPushButton(rayDockContents);
        rayStopRenderingButton->setObjectName(QString::fromUtf8("rayStopRenderingButton"));

        verticalLayout_4->addWidget(rayStopRenderingButton);

        rayDockEmptySpace = new QWidget(rayDockContents);
        rayDockEmptySpace->setObjectName(QString::fromUtf8("rayDockEmptySpace"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rayDockEmptySpace->sizePolicy().hasHeightForWidth());
        rayDockEmptySpace->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(rayDockEmptySpace);

        rayDock->setWidget(rayDockContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), rayDock);
        camtransDock = new QDockWidget(MainWindow);
        camtransDock->setObjectName(QString::fromUtf8("camtransDock"));
        camtransDockContents = new QWidget();
        camtransDockContents->setObjectName(QString::fromUtf8("camtransDockContents"));
        verticalLayout_10 = new QVBoxLayout(camtransDockContents);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        cameraOrbitCheckbox = new QCheckBox(camtransDockContents);
        cameraOrbitCheckbox->setObjectName(QString::fromUtf8("cameraOrbitCheckbox"));

        verticalLayout_10->addWidget(cameraOrbitCheckbox);

        cameraPosition = new QGroupBox(camtransDockContents);
        cameraPosition->setObjectName(QString::fromUtf8("cameraPosition"));
        gridLayout = new QGridLayout(cameraPosition);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(-1, 5, -1, 5);
        cameraPositionLabelX = new QLabel(cameraPosition);
        cameraPositionLabelX->setObjectName(QString::fromUtf8("cameraPositionLabelX"));
        cameraPositionLabelX->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cameraPositionLabelX, 1, 0, 1, 1);

        cameraPositionLabelY = new QLabel(cameraPosition);
        cameraPositionLabelY->setObjectName(QString::fromUtf8("cameraPositionLabelY"));
        cameraPositionLabelY->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cameraPositionLabelY, 1, 1, 1, 1);

        cameraPositionLabelZ = new QLabel(cameraPosition);
        cameraPositionLabelZ->setObjectName(QString::fromUtf8("cameraPositionLabelZ"));
        cameraPositionLabelZ->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cameraPositionLabelZ, 1, 2, 1, 1);

        transX = new QDial(cameraPosition);
        transX->setObjectName(QString::fromUtf8("transX"));
        transX->setMinimumSize(QSize(60, 60));
        transX->setMaximumSize(QSize(60, 60));
        transX->setMinimum(-360);
        transX->setMaximum(360);
        transX->setSingleStep(10);
        transX->setPageStep(30);
        transX->setOrientation(Qt::Horizontal);
        transX->setInvertedControls(true);
        transX->setWrapping(true);

        gridLayout->addWidget(transX, 0, 0, 1, 1);

        transY = new QDial(cameraPosition);
        transY->setObjectName(QString::fromUtf8("transY"));
        transY->setMinimumSize(QSize(60, 60));
        transY->setMaximumSize(QSize(60, 60));
        transY->setMinimum(-360);
        transY->setMaximum(360);
        transY->setSingleStep(10);
        transY->setPageStep(30);
        transY->setOrientation(Qt::Horizontal);
        transY->setInvertedControls(true);
        transY->setWrapping(true);

        gridLayout->addWidget(transY, 0, 1, 1, 1);

        transZ = new QDial(cameraPosition);
        transZ->setObjectName(QString::fromUtf8("transZ"));
        transZ->setMinimumSize(QSize(60, 60));
        transZ->setMaximumSize(QSize(60, 60));
        transZ->setMinimum(-360);
        transZ->setMaximum(360);
        transZ->setSingleStep(10);
        transZ->setPageStep(30);
        transZ->setOrientation(Qt::Horizontal);
        transZ->setInvertedControls(true);
        transZ->setWrapping(true);

        gridLayout->addWidget(transZ, 0, 2, 1, 1);


        verticalLayout_10->addWidget(cameraPosition);

        cameraRotation = new QGroupBox(camtransDockContents);
        cameraRotation->setObjectName(QString::fromUtf8("cameraRotation"));
        cameraRotation->setEnabled(true);
        verticalLayout_13 = new QVBoxLayout(cameraRotation);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(-1, 5, -1, 5);
        cameraRotation_2 = new QWidget(cameraRotation);
        cameraRotation_2->setObjectName(QString::fromUtf8("cameraRotation_2"));
        gridLayout_15 = new QGridLayout(cameraRotation_2);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setVerticalSpacing(18);
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        rotU = new QDial(cameraRotation_2);
        rotU->setObjectName(QString::fromUtf8("rotU"));
        rotU->setMinimumSize(QSize(60, 60));
        rotU->setMaximumSize(QSize(60, 60));
        rotU->setMinimum(-360);
        rotU->setMaximum(360);
        rotU->setSingleStep(10);
        rotU->setPageStep(30);
        rotU->setOrientation(Qt::Horizontal);
        rotU->setInvertedControls(true);
        rotU->setWrapping(true);

        gridLayout_15->addWidget(rotU, 0, 0, 1, 1);

        rotV = new QDial(cameraRotation_2);
        rotV->setObjectName(QString::fromUtf8("rotV"));
        rotV->setMinimumSize(QSize(60, 60));
        rotV->setMaximumSize(QSize(60, 60));
        rotV->setMinimum(-360);
        rotV->setMaximum(360);
        rotV->setSingleStep(10);
        rotV->setPageStep(30);
        rotV->setOrientation(Qt::Horizontal);
        rotV->setInvertedControls(true);
        rotV->setWrapping(true);

        gridLayout_15->addWidget(rotV, 0, 1, 1, 1);

        rotW = new QDial(cameraRotation_2);
        rotW->setObjectName(QString::fromUtf8("rotW"));
        rotW->setMinimumSize(QSize(60, 60));
        rotW->setMaximumSize(QSize(60, 60));
        rotW->setMinimum(-360);
        rotW->setMaximum(360);
        rotW->setSingleStep(10);
        rotW->setPageStep(30);
        rotW->setOrientation(Qt::Horizontal);
        rotW->setInvertedControls(true);
        rotW->setWrapping(true);

        gridLayout_15->addWidget(rotW, 0, 2, 1, 1);

        cameraRotationLabelYaw = new QLabel(cameraRotation_2);
        cameraRotationLabelYaw->setObjectName(QString::fromUtf8("cameraRotationLabelYaw"));
        cameraRotationLabelYaw->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(cameraRotationLabelYaw, 1, 0, 1, 1);

        cameraRotationLabelPitch = new QLabel(cameraRotation_2);
        cameraRotationLabelPitch->setObjectName(QString::fromUtf8("cameraRotationLabelPitch"));
        cameraRotationLabelPitch->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(cameraRotationLabelPitch, 1, 1, 1, 1);

        cameraRotationLabelRoll = new QLabel(cameraRotation_2);
        cameraRotationLabelRoll->setObjectName(QString::fromUtf8("cameraRotationLabelRoll"));
        cameraRotationLabelRoll->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(cameraRotationLabelRoll, 1, 2, 1, 1);


        verticalLayout_13->addWidget(cameraRotation_2);

        resetUpVector = new QPushButton(cameraRotation);
        resetUpVector->setObjectName(QString::fromUtf8("resetUpVector"));

        verticalLayout_13->addWidget(resetUpVector);


        verticalLayout_10->addWidget(cameraRotation);

        cameraResetAxis = new QGroupBox(camtransDockContents);
        cameraResetAxis->setObjectName(QString::fromUtf8("cameraResetAxis"));
        cameraResetAxis->setMinimumSize(QSize(0, 0));
        gridLayout_14 = new QGridLayout(cameraResetAxis);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        xAxisButton = new QPushButton(cameraResetAxis);
        xAxisButton->setObjectName(QString::fromUtf8("xAxisButton"));

        gridLayout_14->addWidget(xAxisButton, 0, 0, 1, 1);

        yAxisButton = new QPushButton(cameraResetAxis);
        yAxisButton->setObjectName(QString::fromUtf8("yAxisButton"));

        gridLayout_14->addWidget(yAxisButton, 1, 0, 1, 1);

        zAxisButton = new QPushButton(cameraResetAxis);
        zAxisButton->setObjectName(QString::fromUtf8("zAxisButton"));

        gridLayout_14->addWidget(zAxisButton, 0, 1, 1, 1);

        axonometricButton = new QPushButton(cameraResetAxis);
        axonometricButton->setObjectName(QString::fromUtf8("axonometricButton"));

        gridLayout_14->addWidget(axonometricButton, 1, 1, 1, 1);


        verticalLayout_10->addWidget(cameraResetAxis);

        cameraFrustum = new QWidget(camtransDockContents);
        cameraFrustum->setObjectName(QString::fromUtf8("cameraFrustum"));
        gridLayout_5 = new QGridLayout(cameraFrustum);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(5);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        cameraFovLabel = new QLabel(cameraFrustum);
        cameraFovLabel->setObjectName(QString::fromUtf8("cameraFovLabel"));

        gridLayout_5->addWidget(cameraFovLabel, 0, 0, 1, 1);

        cameraFovTextbox = new QLineEdit(cameraFrustum);
        cameraFovTextbox->setObjectName(QString::fromUtf8("cameraFovTextbox"));
        cameraFovTextbox->setMinimumSize(QSize(60, 0));
        cameraFovTextbox->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(cameraFovTextbox, 0, 3, 1, 1);

        cameraFovSlider = new QSlider(cameraFrustum);
        cameraFovSlider->setObjectName(QString::fromUtf8("cameraFovSlider"));
        cameraFovSlider->setMinimumSize(QSize(100, 0));
        cameraFovSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(cameraFovSlider, 0, 1, 1, 1);

        cameraNearLabel = new QLabel(cameraFrustum);
        cameraNearLabel->setObjectName(QString::fromUtf8("cameraNearLabel"));

        gridLayout_5->addWidget(cameraNearLabel, 1, 0, 1, 1);

        cameraNearTextbox = new QLineEdit(cameraFrustum);
        cameraNearTextbox->setObjectName(QString::fromUtf8("cameraNearTextbox"));
        cameraNearTextbox->setMinimumSize(QSize(60, 0));
        cameraNearTextbox->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(cameraNearTextbox, 1, 3, 1, 1);

        cameraFarLabel = new QLabel(cameraFrustum);
        cameraFarLabel->setObjectName(QString::fromUtf8("cameraFarLabel"));

        gridLayout_5->addWidget(cameraFarLabel, 2, 0, 1, 1);

        cameraFarTextbox = new QLineEdit(cameraFrustum);
        cameraFarTextbox->setObjectName(QString::fromUtf8("cameraFarTextbox"));
        cameraFarTextbox->setMinimumSize(QSize(60, 0));
        cameraFarTextbox->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(cameraFarTextbox, 2, 3, 1, 1);

        cameraNearSlider = new QSlider(cameraFrustum);
        cameraNearSlider->setObjectName(QString::fromUtf8("cameraNearSlider"));
        cameraNearSlider->setMinimumSize(QSize(100, 0));
        cameraNearSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(cameraNearSlider, 1, 1, 1, 1);

        cameraFarSlider = new QSlider(cameraFrustum);
        cameraFarSlider->setObjectName(QString::fromUtf8("cameraFarSlider"));
        cameraFarSlider->setMinimumSize(QSize(100, 0));
        cameraFarSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(cameraFarSlider, 2, 1, 1, 1);


        verticalLayout_10->addWidget(cameraFrustum);

        resetSliders = new QPushButton(camtransDockContents);
        resetSliders->setObjectName(QString::fromUtf8("resetSliders"));

        verticalLayout_10->addWidget(resetSliders);

        cameraAspectRatio = new QLabel(camtransDockContents);
        cameraAspectRatio->setObjectName(QString::fromUtf8("cameraAspectRatio"));

        verticalLayout_10->addWidget(cameraAspectRatio);

        label = new QLabel(camtransDockContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setWordWrap(true);

        verticalLayout_10->addWidget(label);

        cameraDockEmptySpace = new QWidget(camtransDockContents);
        cameraDockEmptySpace->setObjectName(QString::fromUtf8("cameraDockEmptySpace"));
        sizePolicy2.setHeightForWidth(cameraDockEmptySpace->sizePolicy().hasHeightForWidth());
        cameraDockEmptySpace->setSizePolicy(sizePolicy2);

        verticalLayout_10->addWidget(cameraDockEmptySpace);

        camtransDock->setWidget(camtransDockContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), camtransDock);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 24));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuToolbars = new QMenu(menuBar);
        menuToolbars->setObjectName(QString::fromUtf8("menuToolbars"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuToolbars->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionRevert);
        menuFile->addAction(actionClear);
        menuFile->addAction(actionCopy3Dto2D);
        menuFile->addAction(actionUseOrbitingCamera);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(raySuperSamping, SIGNAL(toggled(bool)), raySuperSamplesTextbox, SLOT(setEnabled(bool)));
        QObject::connect(rayAllButton, SIGNAL(clicked()), MainWindow, SLOT(checkAllRayFeatures()));
        QObject::connect(rayNoneButton, SIGNAL(clicked()), MainWindow, SLOT(uncheckAllRayFeatures()));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), cameraRotation, SLOT(setDisabled(bool)));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), cameraPosition, SLOT(setDisabled(bool)));
        QObject::connect(xAxisButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxisX()));
        QObject::connect(yAxisButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxisY()));
        QObject::connect(axonometricButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxonometric()));
        QObject::connect(transX, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraTranslation()));
        QObject::connect(transY, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraTranslation()));
        QObject::connect(transZ, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraTranslation()));
        QObject::connect(rotU, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraRotationU()));
        QObject::connect(rotW, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraRotationN()));
        QObject::connect(rotV, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraRotationV()));
        QObject::connect(cameraNearSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraNearTextbox, SIGNAL(textChanged(QString)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraFarSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraFarTextbox, SIGNAL(textChanged(QString)), MainWindow, SLOT(updateCameraClip()));
        QObject::connect(cameraFovSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(updateCameraHeightAngle()));
        QObject::connect(cameraFovTextbox, SIGNAL(textChanged(QString)), MainWindow, SLOT(updateCameraHeightAngle()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(fileSave()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(fileOpen()));
        QObject::connect(rayRenderButton, SIGNAL(clicked()), MainWindow, SLOT(renderImage()));
        QObject::connect(actionNew, SIGNAL(triggered()), MainWindow, SLOT(fileNew()));
        QObject::connect(resetUpVector, SIGNAL(clicked()), MainWindow, SLOT(resetUpVector()));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), cameraResetAxis, SLOT(setDisabled(bool)));
        QObject::connect(rayStopRenderingButton, SIGNAL(clicked()), canvas2D, SLOT(cancelRender()));
        QObject::connect(actionCopy3Dto2D, SIGNAL(triggered()), MainWindow, SLOT(fileCopy3Dto2D()));
        QObject::connect(zAxisButton, SIGNAL(clicked()), MainWindow, SLOT(setCameraAxisZ()));
        QObject::connect(actionClear, SIGNAL(triggered()), MainWindow, SLOT(clearImage()));
        QObject::connect(actionRevert, SIGNAL(triggered()), MainWindow, SLOT(revertImage()));
        QObject::connect(resetSliders, SIGNAL(clicked()), MainWindow, SLOT(resetSliders()));
        QObject::connect(actionUseOrbitingCamera, SIGNAL(toggled(bool)), cameraOrbitCheckbox, SLOT(setChecked(bool)));
        QObject::connect(cameraOrbitCheckbox, SIGNAL(toggled(bool)), actionUseOrbitingCamera, SLOT(setChecked(bool)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CS 123: Introduction to Computer Graphics", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "&New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "&Open...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "&Save...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionRevert->setText(QApplication::translate("MainWindow", "&Revert Image", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRevert->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy3Dto2D->setText(QApplication::translate("MainWindow", "Copy &3D tab to 2D tab", nullptr));
        actionClear->setText(QApplication::translate("MainWindow", "&Clear Image", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear Image", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionClear->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionUseOrbitingCamera->setText(QApplication::translate("MainWindow", "&Use Orbiting Camera", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUseOrbitingCamera->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_NO_SHORTCUT
        tabWidget->setTabText(tabWidget->indexOf(tab2D), QApplication::translate("MainWindow", "2D", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3D), QApplication::translate("MainWindow", "3D", nullptr));
        rayDock->setWindowTitle(QApplication::translate("MainWindow", "&Ray", nullptr));
        rayAllButton->setText(QApplication::translate("MainWindow", "All", nullptr));
        rayNoneButton->setText(QApplication::translate("MainWindow", "None", nullptr));
        rayFeatures->setTitle(QApplication::translate("MainWindow", "Features", nullptr));
        raySuperSamping->setText(QApplication::translate("MainWindow", "Super sampling", nullptr));
        raySuperSamplesLabel->setText(QApplication::translate("MainWindow", "sqrt(samples)", nullptr));
        raySuperSamplesTextbox->setText(QString());
        rayAntiAliasing->setText(QApplication::translate("MainWindow", "Anti-aliasing", nullptr));
        rayShadows->setText(QApplication::translate("MainWindow", "Shadows", nullptr));
        rayTextureMapping->setText(QApplication::translate("MainWindow", "Texture Mapping", nullptr));
        rayReflection->setText(QApplication::translate("MainWindow", "Reflection", nullptr));
        rayRefraction->setText(QApplication::translate("MainWindow", "Refraction", nullptr));
        rayMultiThreading->setText(QApplication::translate("MainWindow", "Multithreading", nullptr));
        rayUseKDTree->setText(QApplication::translate("MainWindow", "Use KD tree", nullptr));
        rayLighting->setTitle(QApplication::translate("MainWindow", "Lighting", nullptr));
        rayPointLights->setText(QApplication::translate("MainWindow", "Point lights", nullptr));
        rayDirectionalLights->setText(QApplication::translate("MainWindow", "Directional lights", nullptr));
        raySpotLights->setText(QApplication::translate("MainWindow", "Spot lights", nullptr));
        rayRenderButton->setText(QApplication::translate("MainWindow", "Render!", nullptr));
        rayStopRenderingButton->setText(QApplication::translate("MainWindow", "Stop rendering", nullptr));
        camtransDock->setWindowTitle(QApplication::translate("MainWindow", "&Camtrans", nullptr));
        cameraOrbitCheckbox->setText(QApplication::translate("MainWindow", "Use orbit camera instead", nullptr));
        cameraPosition->setTitle(QApplication::translate("MainWindow", "Translation", nullptr));
        cameraPositionLabelX->setText(QApplication::translate("MainWindow", "X", nullptr));
        cameraPositionLabelY->setText(QApplication::translate("MainWindow", "Y", nullptr));
        cameraPositionLabelZ->setText(QApplication::translate("MainWindow", "Z", nullptr));
        cameraRotation->setTitle(QApplication::translate("MainWindow", "Rotation", nullptr));
        cameraRotationLabelYaw->setText(QApplication::translate("MainWindow", "U", nullptr));
        cameraRotationLabelPitch->setText(QApplication::translate("MainWindow", "V", nullptr));
        cameraRotationLabelRoll->setText(QApplication::translate("MainWindow", "W", nullptr));
        resetUpVector->setText(QApplication::translate("MainWindow", "Reset up vector", nullptr));
        cameraResetAxis->setTitle(QApplication::translate("MainWindow", "Reset", nullptr));
        xAxisButton->setText(QApplication::translate("MainWindow", "X axis", nullptr));
        yAxisButton->setText(QApplication::translate("MainWindow", "Y axis", nullptr));
        zAxisButton->setText(QApplication::translate("MainWindow", "Z axis", nullptr));
        axonometricButton->setText(QApplication::translate("MainWindow", "Axonometric", nullptr));
        cameraFovLabel->setText(QApplication::translate("MainWindow", "FOV", nullptr));
        cameraNearLabel->setText(QApplication::translate("MainWindow", "Near", nullptr));
        cameraFarLabel->setText(QApplication::translate("MainWindow", "Far", nullptr));
        resetSliders->setText(QApplication::translate("MainWindow", "Reset FOV / Near / Far", nullptr));
        cameraAspectRatio->setText(QApplication::translate("MainWindow", "Aspect ratio:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Resize the window to change the aspect ratio.", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuToolbars->setTitle(QApplication::translate("MainWindow", "&Toolbars", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
