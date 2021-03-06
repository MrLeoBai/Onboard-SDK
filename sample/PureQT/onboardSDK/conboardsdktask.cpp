#include "conboardsdktask.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include <cmdIO.h>
#include <cmdSettings.h>
#include <cmdCoreAPI.h>
#include <cmdFlight.h>
#include <cmdFollow.h>
#include <cmdHotPoint.h>
#include <cmdWayPoint.h>
#include <cmdVirtualRC.h>
#include <cmdCamera.h>

using namespace std;

TaskSetItem cmdTaskSet[] = {
    TASK_ITEM(addTask, 0),   //
    TASK_ITEM(waitInput, 0), //
    TASK_ITEM(help, 0),		 //

    TASK_ITEM(SS, 0),	 //
    TASK_ITEM(idSS, 0),   //
    TASK_ITEM(keySS, 0),  //
    TASK_ITEM(saveSS, 0), //
    TASK_ITEM(loadSS, 0), //
    TASK_ITEM(spSS, 0),   //

    TASK_ITEM(CA, 0),   //
    TASK_ITEM(acCA, 0), //
    TASK_ITEM(vsCA, 0), //
    TASK_ITEM(bfCA, 0), //
    TASK_ITEM(bdCA, 0), //
    TASK_ITEM(ctCA, 0), //
    TASK_ITEM(syCA, 0), //

    TASK_ITEM(FC, 0),   //
    TASK_ITEM(tkFC, 0), //
    TASK_ITEM(mcFC, 0), //
    TASK_ITEM(flFC, 0), //

    TASK_ITEM(FM, 0),		 //
    TASK_ITEM(startFM, 0),   //
    TASK_ITEM(stopFM, 0),	//
    TASK_ITEM(pauseFM, 0),   //
    TASK_ITEM(restartFM, 0), //
    TASK_ITEM(updateFM, 0),  //

    TASK_ITEM(HP, 0),		 //
    TASK_ITEM(startHP, 0),   //
    TASK_ITEM(stopHP, 0),	//
    TASK_ITEM(pauseHP, 0),   //
    TASK_ITEM(restartHP, 0), //

    TASK_ITEM(VC, 0),	  //
    TASK_ITEM(startVC, 0), //
    TASK_ITEM(stopVC, 0),  //
    TASK_ITEM(ctVC, 0),	//

    TASK_ITEM(WP, 0),		//
    TASK_ITEM(initWP, 0),   //
    TASK_ITEM(startWP, 0),  //
    TASK_ITEM(stopWP, 0),   //
    TASK_ITEM(pauseWP, 0),  //
    TASK_ITEM(restartWP, 0), //
    TASK_ITEM(apWP, 0),		//

    TASK_ITEM(CC, 0),   //
    TASK_ITEM(cmCC, 0), //
    TASK_ITEM(agCC, 0), //
    TASK_ITEM(sgCC, 0), //
};

ConboardSDKScript::ConboardSDKScript(CoreAPI* api)
    : Script(api, cmdTaskSet, sizeof(cmdTaskSet) / sizeof(TaskSetItem))
{
}

TaskSetItem ConboardSDKScript::match(const char* name) { return Script::match((UserData)name); }

void ConboardSDKScript::addTask(const char* Name, UserData Data,  DJI::time_ms Timeout)
{
    Script::addTask((UserData)Name, Data,Timeout);
}

ScriptThread::ScriptThread(ConboardSDKScript* Script, QObject* parent) : QThread(parent)
{
    script = Script;
}

void ScriptThread::run()
{
    while (1)
    {
        script->addTask("addTask");
        script->run();
    }
}
