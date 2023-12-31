// -*- C++ -*- generated by wxGlade 0.5 on Wed May 30 14:46:15 2007 from Z:\WIP\CookTimer\CookTimer.wxg

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/taskbar.h>
#include <wx/sound.h>

#include <vector>

#ifndef COOKTIMERFRAME_H
#define COOKTIMERFRAME_H

// begin wxGlade: ::dependencies
#include <wx/spinctrl.h>
#include <wx/statline.h>
// end wxGlade

class CookTimerTaskBarIcon: public wxTaskBarIcon
	{
	public:
#if defined(__WXCOCOA__)
		CookTimerTaskBarIcon(wxTaskBarIconType iconType = DEFAULT_TYPE)
			:   wxTaskBarIcon(iconType)
#else
				CookTimerTaskBarIcon()
#endif
			{
			}

		wxTopLevelWindow *window;

	private:

		// event handlers
		void OnLeftButtonDClick(wxTaskBarIconEvent &evt);

		DECLARE_EVENT_TABLE()
	};

class CookTimerFrame: public wxFrame
	{
	public:
    // begin wxGlade: CookTimerFrame::ids
    enum {
        ID_StartStopButton = wxID_HIGHEST + 1000,
        ID_ResetButton = wxID_HIGHEST + 1001,
        ID_AutoRestartCheckBox = wxID_HIGHEST + 1002
    };
    // end wxGlade

		CookTimerFrame(wxWindow* parent);
		~CookTimerFrame();

	private:
    // begin wxGlade: CookTimerFrame::methods
    void set_properties();
    void do_layout();
    // end wxGlade


		unsigned int GetPeriod() const;
		void UpdateControls();
		unsigned int GetCustomValue() const;
		bool IsCustomSelected() const;

		void OnTimer(wxTimerEvent &event);
		void OnStartStopButton(wxCommandEvent &evt);
		void OnResetButton(wxCommandEvent &evt);
		void OnIconize(wxIconizeEvent &evt);
		void OnPresetsRadioBox(wxCommandEvent &evt) { UpdateControls(); }
		void OnAutoResetChecked(wxCommandEvent &evt);

		wxTimer _timer;

		int _seconds;
		bool _running, _reset;
		wxRadioBox *_presetsRadioBox;
		std::vector<unsigned int> _times;
		wxSound timeoutSound;

		CookTimerTaskBarIcon   *_taskBarIcon;
#if defined(__WXCOCOA__)
		CookTimerTaskBarIcon   *_dockIcon;
#endif

	protected:
    // begin wxGlade: CookTimerFrame::attributes
    wxSpinCtrl* _hoursSpinCtrl;
    wxSpinCtrl* _minutesSpinCtrl;
    wxSpinCtrl* _secondsSpinCtrl;
    wxStaticText* _remainingTimeStatic;
    wxGauge* _progressBar;
    wxButton* _startStopButton;
    wxButton* _resetButton;
    wxCheckBox* _autoRestartCheckbox;
    wxCheckBox* _ringForeverCheckbox;
    wxPanel* rootPanel;
    // end wxGlade

		DECLARE_EVENT_TABLE();
	}; // wxGlade: end class


#endif // COOKTIMERFRAME_H
