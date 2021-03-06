#include "gl_framework.hpp"
#include "model.hpp"


namespace csX75 {
    //! Initialize GL State

    void initGL(void) {
        //Set framebuffer clear color
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        //Set depth buffer furthest depth
        glClearDepth(1.0);
        //Set depth test to less-than
        glDepthFunc(GL_LESS);
        //Enable depth testing
        glEnable(GL_DEPTH_TEST);
    }

    //!GLFW Error Callback

    void error_callback(int error, const char* description) {
        std::cerr << description << std::endl;
    }

    //!GLFW framebuffer resize callback

    void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        //!Resize the viewport to fit the window size - draw to entire window
        glViewport(0, 0, width, height);
    }

    //!GLFW keyboard callback

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        csX75::model_t* mymodel = reinterpret_cast<csX75::model_t*> (glfwGetWindowUserPointer(window));
        //!Close the window if the ESC key was pressed
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
        else if (key == GLFW_KEY_1 && action == GLFW_PRESS)
            mymodel->objtype = obj_type::human;
        else if (key == GLFW_KEY_2 && action == GLFW_PRESS)
            mymodel->objtype = obj_type::alien;
        else if (key == GLFW_KEY_3 && action == GLFW_PRESS)
            mymodel->objtype = obj_type::box;

        if (mymodel->objtype == obj_type::human) {
            if (key == GLFW_KEY_Q && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::hip);
            else if (key == GLFW_KEY_W && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::torso);
            else if (key == GLFW_KEY_E && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::larm);
            else if (key == GLFW_KEY_R && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::rarm);
            else if (key == GLFW_KEY_T && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::lleg);
            else if (key == GLFW_KEY_Y && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::rleg);
            else if (key == GLFW_KEY_U && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::head);
            else if (key == GLFW_KEY_A && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::rlarm);
            else if (key == GLFW_KEY_S && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::llarm);
            else if (key == GLFW_KEY_D && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::llleg);
            else if (key == GLFW_KEY_F && action == GLFW_PRESS)
                mymodel->newhuman->set_curr_limb(limb_t::rlleg);
            else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
                mymodel->newhuman->rotate_y_cc();
            else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
                mymodel->newhuman->rotate_y_ccw();
            else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
                mymodel->newhuman->rotate_x_cc();
            else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
                mymodel->newhuman->rotate_x_ccw();
            else if (key == GLFW_KEY_N && action == GLFW_PRESS)
                mymodel->newhuman->rotate_z_cc();
            else if (key == GLFW_KEY_M && action == GLFW_PRESS)
                mymodel->newhuman->rotate_z_ccw();
            else if (key == GLFW_KEY_EQUAL && action == GLFW_PRESS)
                mymodel->newhuman->trans_y_inc();
            else if (key == GLFW_KEY_MINUS && action == GLFW_PRESS)
                mymodel->newhuman->trans_y_dec();
            
        } else if (mymodel->objtype == obj_type::alien) {
            if (key == GLFW_KEY_Q && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::mainbody);
            else if (key == GLFW_KEY_W && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::larm);
            else if (key == GLFW_KEY_E && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::rarm);
            else if (key == GLFW_KEY_R && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::lleg);
            else if (key == GLFW_KEY_T && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::rleg);
            else if (key == GLFW_KEY_Y && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::rlarm);
            else if (key == GLFW_KEY_U && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::llarm);
            else if (key == GLFW_KEY_I && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::llleg);
            else if (key == GLFW_KEY_O && action == GLFW_PRESS)
                mymodel->newalien->set_curr_limb(part_t::rlleg);
            else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
                mymodel->newalien->rotate_y_cc();
            else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
                mymodel->newalien->rotate_y_ccw();
            else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
                mymodel->newalien->rotate_x_cc();
            else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
                mymodel->newalien->rotate_x_ccw();
            else if (key == GLFW_KEY_N && action == GLFW_PRESS)
                mymodel->newalien->rotate_z_cc();
            else if (key == GLFW_KEY_M && action == GLFW_PRESS)
                mymodel->newalien->rotate_z_ccw();
            else if (key == GLFW_KEY_EQUAL && action == GLFW_PRESS)
                mymodel->newalien->trans_y_inc();
            else if (key == GLFW_KEY_MINUS && action == GLFW_PRESS)
                mymodel->newalien->trans_y_dec();
        }
        else if (mymodel->objtype == obj_type::box) {
            if (key == GLFW_KEY_UP && action == GLFW_PRESS)
                mymodel->newbox->open_box();
            else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
                mymodel->newbox->close_box();
            else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
                mymodel->newbox->rotate_ccw();
            else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
                mymodel->newbox->rotate_cw();

        }
    }
};



