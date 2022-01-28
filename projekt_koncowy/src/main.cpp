#include <gtkmm-4.0/gtkmm.h>

#include "Biblioteka.hpp"

#include <iostream>

using namespace std;

class MyWindow : public Gtk::Window {
    public:
        MyWindow() : m_button{"asd"} {
            set_title("Hello world!");
            set_default_size(640, 480);

            m_button.set_label("dsa");
            m_button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
            set_child(m_button);
        }
    protected:
        Gtk::Button m_button;

        void on_button_clicked() {
            cout << "asd" << endl;
        }

};

int main(int argc, char* argv[]) {

    Biblioteka b{};

    auto app = Gtk::Application::create("me.madix.test");

    return app->make_window_and_run<MyWindow>(argc, argv);

}

