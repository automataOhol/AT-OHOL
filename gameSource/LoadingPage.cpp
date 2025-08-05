#include "LoadingPage.h"

#include "message.h"
#include "minorGems/game/drawUtils.h"


void LoadingPage::setCurrentPhase( const char *inPhaseName ) {
    mPhaseName = inPhaseName;
    }


        
void LoadingPage::setCurrentProgress( float inProgress ) {
    mProgress = inProgress;
    }

        

void LoadingPage::draw(doublePair inViewCenter, double inViewSize) {
    doublePair labelPos = { 0, 50 };
    drawMessage("PIELIFE - SSC SERVICES", labelPos, false);

    labelPos.y = -25;
    drawMessage(mPhaseName, labelPos, false);

    if (mShowProgress) {
        // center position of the progress bar
        doublePair barPos = { 0, -160 };

        double barWidth = 200;
        double barHeight = 20;

        double halfW = barWidth / 2;
        double halfH = barHeight / 2;

        // border
        setDrawColor(1, 1, 1, 1);
        drawRect(barPos.x - halfW, barPos.y - halfH,
                 barPos.x + halfW, barPos.y + halfH);

        // inner black
        setDrawColor(0, 0, 0, 1);
        drawRect(barPos.x - halfW + 2, barPos.y - halfH + 2,
                 barPos.x + halfW - 2, barPos.y + halfH - 2);

        // progress fill
        setDrawColor(0.8f, 0.8f, 0.8f, 1);
        drawRect(barPos.x - halfW + 2, barPos.y - halfH + 2,
                 barPos.x - halfW + 2 + mProgress * (barWidth - 4), 
                 barPos.y + halfH - 2);
    }
}
